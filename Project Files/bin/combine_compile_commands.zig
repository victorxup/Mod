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

    try writer.writeAll("[");
    while (args_iter.next()) |arg| {
        const comp_db = try std.fs.cwd().readFileAlloc(gpa, arg, std.math.maxInt(usize));
        defer gpa.free(comp_db);
        try writer.writeAll(comp_db);
        try writer.writeAll(",");
    }
    try writer.writeAll("]\n");
}
