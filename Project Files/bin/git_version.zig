const std = @import("std");
const assert = std.debug.assert;

pub fn main() !void {
    var gpa_instance = std.heap.GeneralPurposeAllocator(.{}){};
    defer assert(gpa_instance.deinit() == .ok);
    const gpa = gpa_instance.allocator();

    const writer = std.io.getStdOut().writer();

    var args_iter = try std.process.argsWithAllocator(gpa);
    defer args_iter.deinit();
    _ = args_iter.next(); // argv[0] is the executable

    const git_rev_path = args_iter.next() orelse @panic("Missing git revision parameter");
    const git_rev = try std.fs.cwd().readFileAlloc(gpa, git_rev_path, std.math.maxInt(usize));
    defer gpa.free(git_rev);
    assert(git_rev.len > 0);
    assert(git_rev[git_rev.len - 1] == '\n');

    try writer.print(
        \\#ifndef AUTO_GIT_VERSION_H
        \\#define AUTO_GIT_VERSION_H
        \\#pragma once
        \\char const* szGitVersion = "{s}";
        \\#endif
    , .{git_rev[0 .. git_rev.len - 1]});
}
