#include "CvGameCoreDLL.h"

//
// File responsbile for building project PCH
//

//
// Test that enum values hardcoded in the exe stays at what the exe expects.
// While we do not know precisely which values are hardcoded we do know that some are.
// If a value is hardcoded, add the entire enum here just to be safe.
//    Nightinggale
//

static_assert(WIDGET_PLOT_LIST == WidgetTypes(0));
static_assert(WIDGET_PLOT_LIST_SHIFT == WidgetTypes(1));
static_assert(WIDGET_CITY_SCROLL == WidgetTypes(2));
static_assert(WIDGET_LIBERATE_CITY == WidgetTypes(3));
static_assert(WIDGET_CITY_NAME == WidgetTypes(4));
static_assert(WIDGET_UNIT_NAME == WidgetTypes(5));
static_assert(WIDGET_CREATE_GROUP == WidgetTypes(6));
static_assert(WIDGET_DELETE_GROUP == WidgetTypes(7));
static_assert(WIDGET_TRAIN == WidgetTypes(8));
static_assert(WIDGET_CONSTRUCT == WidgetTypes(9));
static_assert(WIDGET_CONVINCE == WidgetTypes(10));
static_assert(WIDGET_HURRY == WidgetTypes(11));
static_assert(WIDGET_PLAYER_HURRY == WidgetTypes(12));
static_assert(WIDGET_MENU_ICON == WidgetTypes(13));
static_assert(WIDGET_ACTION == WidgetTypes(14));
static_assert(WIDGET_CITIZEN == WidgetTypes(15));
static_assert(WIDGET_CONTACT_CIV == WidgetTypes(16));
static_assert(WIDGET_SCORE_BREAKDOWN == WidgetTypes(17));
static_assert(WIDGET_ZOOM_CITY == WidgetTypes(18));
static_assert(WIDGET_END_TURN == WidgetTypes(19));
static_assert(WIDGET_AUTOMATE_CITIZENS == WidgetTypes(20));
static_assert(WIDGET_AUTOMATE_PRODUCTION == WidgetTypes(21));
static_assert(WIDGET_EMPHASIZE == WidgetTypes(22));
static_assert(WIDGET_DIPLOMACY_RESPONSE == WidgetTypes(23));
static_assert(WIDGET_GENERAL == WidgetTypes(24));
static_assert(WIDGET_FILE_LISTBOX == WidgetTypes(25));
static_assert(WIDGET_FILE_EDITBOX == WidgetTypes(26));
static_assert(WIDGET_WB_UNITNAME_EDITBOX == WidgetTypes(27));
static_assert(WIDGET_WB_CITYNAME_EDITBOX == WidgetTypes(28));
static_assert(WIDGET_WB_SAVE_BUTTON == WidgetTypes(29));
static_assert(WIDGET_WB_LOAD_BUTTON == WidgetTypes(30));
static_assert(WIDGET_WB_ALL_PLOTS_BUTTON == WidgetTypes(31));
static_assert(WIDGET_WB_LANDMARK_BUTTON == WidgetTypes(32));
static_assert(WIDGET_WB_ERASE_BUTTON == WidgetTypes(33));
static_assert(WIDGET_WB_EXIT_BUTTON == WidgetTypes(34));
static_assert(WIDGET_WB_UNIT_EDIT_BUTTON == WidgetTypes(35));
static_assert(WIDGET_WB_CITY_EDIT_BUTTON == WidgetTypes(36));
static_assert(WIDGET_WB_NORMAL_PLAYER_TAB_MODE_BUTTON == WidgetTypes(37));
static_assert(WIDGET_WB_NORMAL_MAP_TAB_MODE_BUTTON == WidgetTypes(38));
static_assert(WIDGET_WB_REVEAL_TAB_MODE_BUTTON == WidgetTypes(39));
static_assert(WIDGET_WB_DIPLOMACY_MODE_BUTTON == WidgetTypes(40));
static_assert(WIDGET_WB_REVEAL_ALL_BUTTON == WidgetTypes(41));
static_assert(WIDGET_WB_UNREVEAL_ALL_BUTTON == WidgetTypes(42));
static_assert(WIDGET_WB_REGENERATE_MAP == WidgetTypes(43));
static_assert(WIDGET_TRADE_ITEM == WidgetTypes(44));
static_assert(WIDGET_UNIT_MODEL == WidgetTypes(45));
static_assert(WIDGET_POPUP_QUEUE == WidgetTypes(46));
static_assert(WIDGET_PYTHON == WidgetTypes(47));
static_assert(WIDGET_HELP_DEFENSE == WidgetTypes(48));
static_assert(WIDGET_HELP_POPULATION == WidgetTypes(49));
static_assert(WIDGET_HELP_REBEL == WidgetTypes(50));
static_assert(WIDGET_HELP_GREAT_GENERAL == WidgetTypes(51));
static_assert(WIDGET_HELP_SELECTED == WidgetTypes(52));
static_assert(WIDGET_HELP_YIELD == WidgetTypes(53));
static_assert(WIDGET_HELP_PROMOTION == WidgetTypes(54));
static_assert(WIDGET_HELP_UNIT_PROMOTION == WidgetTypes(55));
static_assert(WIDGET_CHOOSE_EVENT == WidgetTypes(56));
static_assert(WIDGET_PEDIA_JUMP_TO_UNIT == WidgetTypes(57));
static_assert(WIDGET_PEDIA_JUMP_TO_PROFESSION == WidgetTypes(58));
static_assert(WIDGET_PEDIA_JUMP_TO_BUILDING == WidgetTypes(59));
static_assert(WIDGET_PEDIA_BACK == WidgetTypes(60));
static_assert(WIDGET_PEDIA_FORWARD == WidgetTypes(61));
static_assert(WIDGET_PEDIA_JUMP_TO_BONUS == WidgetTypes(62));
static_assert(WIDGET_PEDIA_MAIN == WidgetTypes(63));
static_assert(WIDGET_PEDIA_JUMP_TO_PROMOTION == WidgetTypes(64));
static_assert(WIDGET_PEDIA_JUMP_TO_IMPROVEMENT == WidgetTypes(65));
static_assert(WIDGET_PEDIA_JUMP_TO_CIVIC == WidgetTypes(66));
static_assert(WIDGET_PEDIA_JUMP_TO_CIV == WidgetTypes(67));
static_assert(WIDGET_PEDIA_JUMP_TO_LEADER == WidgetTypes(68));
static_assert(WIDGET_PEDIA_JUMP_TO_TERRAIN == WidgetTypes(69));
static_assert(WIDGET_PEDIA_JUMP_TO_YIELDS == WidgetTypes(70));
static_assert(WIDGET_PEDIA_JUMP_TO_FEATURE == WidgetTypes(71));
static_assert(WIDGET_PEDIA_JUMP_TO_FATHER == WidgetTypes(72));
static_assert(WIDGET_TURN_EVENT == WidgetTypes(73));
static_assert(WIDGET_PEDIA_DESCRIPTION == WidgetTypes(74));
static_assert(WIDGET_PEDIA_DESCRIPTION_NO_HELP == WidgetTypes(75));
static_assert(WIDGET_DEAL_KILL == WidgetTypes(76));
static_assert(WIDGET_MINIMAP_HIGHLIGHT == WidgetTypes(77));
static_assert(WIDGET_PRODUCTION_MOD_HELP == WidgetTypes(78));
static_assert(WIDGET_LEADERHEAD == WidgetTypes(79));
static_assert(WIDGET_LEADER_LINE == WidgetTypes(80));
static_assert(WIDGET_CLOSE_SCREEN == WidgetTypes(81));
static_assert(WIDGET_GLOBELAYER == WidgetTypes(82));
static_assert(WIDGET_GLOBELAYER_OPTION == WidgetTypes(83));
static_assert(WIDGET_GLOBELAYER_TOGGLE == WidgetTypes(84));
static_assert(WIDGET_CITY_UNIT_ASSIGN_PROFESSION == WidgetTypes(85));
static_assert(WIDGET_MOVE_CARGO_TO_CITY == WidgetTypes(86));
static_assert(WIDGET_RECEIVE_MOVE_CARGO_TO_CITY == WidgetTypes(87));
static_assert(WIDGET_MOVE_CARGO_TO_TRANSPORT == WidgetTypes(88));
static_assert(WIDGET_RECEIVE_MOVE_CARGO_TO_TRANSPORT == WidgetTypes(89));
static_assert(WIDGET_CREATE_TRADE_ROUTE == WidgetTypes(90));
static_assert(WIDGET_EDIT_TRADE_ROUTE == WidgetTypes(91));
static_assert(WIDGET_YIELD_IMPORT_EXPORT == WidgetTypes(92));
static_assert(WIDGET_ASSIGN_CITIZEN_TO_PLOT == WidgetTypes(93));
static_assert(WIDGET_ASSIGN_TRADE_ROUTE == WidgetTypes(94));
static_assert(WIDGET_EJECT_CITIZEN == WidgetTypes(95));
static_assert(WIDGET_SHIP_CARGO == WidgetTypes(96));
static_assert(WIDGET_DOCK == WidgetTypes(97));
static_assert(WIDGET_SAIL == WidgetTypes(98));
static_assert(WIDGET_GOTO_CITY == WidgetTypes(99));
