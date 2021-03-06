//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
// Copyright (c) 2011-2014 Mario 'rlyeh' Rodriguez
// Copyright (c) 2013 Florian Deconinck
// Copyright (c) 2013 Adrien Herubel
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

// Source altered and distributed from https://github.com/r-lyeh/imgui

#ifndef IMGUI_HPP
#define IMGUI_HPP

#include <string>
#include <vector>

enum imguiIntersection
{
        IMGUI_SECTION_INSIDE = -1,
        IMGUI_SECTION_BORDER = 0,
        IMGUI_SECTION_OUTSIDE = 1
};

enum imguiMouseButton
{
        IMGUI_MOUSE_BUTTON_LEFT = 0x01,
        IMGUI_MOUSE_BUTTON_RIGHT = 0x02,
};

enum imguiTextAlign // same than fontstash
{
        // Horizontal align
        IMGUI_ALIGN_LEFT         = 1<<0, // Default
        IMGUI_ALIGN_CENTER       = 1<<1,
        IMGUI_ALIGN_RIGHT        = 1<<2,
        // Vertical align
        IMGUI_ALIGN_TOP          = 1<<3,
        IMGUI_ALIGN_MIDDLE       = 1<<4,
        IMGUI_ALIGN_BOTTOM       = 1<<5,
        IMGUI_ALIGN_BASELINE     = 1<<6  // Default
};

void imguiBeginFrame(int mx, int my, unsigned char mbut, int scroll, unsigned unicode=0);
void imguiEndFrame();

// masking

bool imguiBeginScrollArea(const char* name, int x, int y, int w, int h, int* scroll=0, bool rounded=true);
void imguiEndScrollArea();

// layout

void imguiIndent();
void imguiUnindent();
void imguiSeparator();
void imguiSeparatorLine();

void imguiStackPush();
 int imguiStackSet( int stackpos );
void imguiSpaceDiv();
void imguiSpaceMul();
void imguiSpaceShift();
void imguiSpaceUnshift();

// imguiPushLayout(Vert/Horiz);
// imguiPopLayout();

//void imguiTab();
//void imguiTabLine();
//void imguiFeed();

// widgets

bool imguiButton(const char* text);
bool imguiCheck(const char* text, bool checked);
bool imguiCollapse(const char* text, const char* subtext, bool checked);
bool imguiItem(const char* text);
bool imguiText(const char* text);
bool imguiTextInput(const char* text, std::vector<unsigned> &utf32, bool isPassword = false);
void imguiLabel(const char* text);
void imguiValue(const char* text);
bool imguiSlider(const char* text, float* val, float vmin, float vmax, float vinc, const char *format = "%d");
bool imguiRange(const char* text, float* val0, float* val1, float vmin, float vmax, float vinc, const char *format = "%d - %d");
bool imguiList(const char* text, size_t n_options, const char** options, int &choosing, int &choice, int *scrollY = 0);
bool imguiRadio(const char* text, size_t n_options, const char** options, int &clicked);
void imguiPair(const char *text, const char *value);
void imguiProgressBar(const char* text, float val, bool show_decimals = false);
bool imguiBitmask(const char* text, unsigned* mask, int bits);
bool imguiRotatorySlider(const char *text, float *val, float vmin, float vmax, float vinc, const char *format = "%d");
bool imguiQuadRange(const char* text, float *val0, float *val1, float vmin, float vmax, float vinc, float *valLO, float *valHI, const char *format = "%d - %d");
bool imguiXYSlider(const char* text, float* valx, float * valy, float height, float vinc, const char *format = "(%d,%d)");
bool imguiLoadingBar( int flow = 0, float radius = 25.f );
bool imguiIcon( unsigned icon );
 int imguiToolbar( const std::vector<unsigned> &icons );
bool imguiImage( unsigned texture_id );

// control
bool imguiWheel( unsigned id );
bool imguiClicked( unsigned id );
bool imguiClicked2( unsigned id );
bool imguiTrigger( unsigned id );
bool imguiHold( unsigned id );
bool imguiRelease( unsigned id );
bool imguiIdle( unsigned id );
bool imguiDrag( unsigned id );
bool imguiDrop( unsigned id );
bool imguiOver( unsigned id );
bool imguiHot( unsigned id );
bool imguiActive( unsigned id );
bool imguiIsIdle();
unsigned imguiId();

//bool imguiLink();
//      bool imguiImage();
//bool imguiUnlink();

// rendering
void imguiDrawText(int x, int y, imguiTextAlign align, const char* text, unsigned int color);
void imguiDrawLine(float x0, float y0, float x1, float y1, float r, unsigned int color);
void imguiDrawLines( const std::vector<float> &points2d, float r, unsigned int color);
void imguiDrawRoundedRect(float x, float y, float w, float h, float r, unsigned int color);
void imguiDrawRect(float x, float y, float w, float h, unsigned int color);
void imguiDrawArc(float x, float y, float radius, float from, float to, unsigned int color);
void imguiDrawCircle(float x, float y, float radius, unsigned int color);

// text
int imguiTextLength(const char *text);
// utf32 to utf8
std::string imguiTextConv( const unsigned &utf32 );
std::string imguiTextConv( const std::vector<unsigned>& utf32 );
// ascii to utf32
std::vector<unsigned> imguiTextConv(const std::string& ascii );

// color
unsigned int imguiHSLA(float h, float s, float l, unsigned char a=255);
unsigned int imguiRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
void imguiPushColor( unsigned int col );
void imguiPopColor();
void imguiPushColorTheme();

//
int imguiShowDialog( const char *text, int *answer );

// enable
void imguiPushEnable( int enabled = 1 );
void imguiPopEnable();

// feed
void imguiBack(); // \r
void imguiNext(); // \n

// mouse
enum {
        IMGUI_MOUSE_ICON_ARROW = 1,
        IMGUI_MOUSE_ICON_HAND = 2
};
int imguiGetMouseCursor();


// built-in icons (http://www.entypo.com)
enum {
        IMGUI_ICON_ENT_PHONE = 0x1F4DE,
        IMGUI_ICON_ENT_MOBILE = 0x1F4F1,
        IMGUI_ICON_ENT_MOUSE = 0xE789,
        IMGUI_ICON_ENT_ADDRESS = 0xE723,
        IMGUI_ICON_ENT_MAIL = 0x2709,
        IMGUI_ICON_ENT_PAPER_PLANE = 0x1F53F,
        IMGUI_ICON_ENT_PENCIL = 0x270E,
        IMGUI_ICON_ENT_FEATHER = 0x2712,
        IMGUI_ICON_ENT_ATTACH = 0x1F4CE,
        IMGUI_ICON_ENT_INBOX = 0xE777,
        IMGUI_ICON_ENT_REPLY = 0xE712,
        IMGUI_ICON_ENT_REPLY_ALL = 0xE713,
        IMGUI_ICON_ENT_FORWARD = 0x27A6,
        IMGUI_ICON_ENT_USER = 0x1F464,
        IMGUI_ICON_ENT_USERS = 0x1F465,
        IMGUI_ICON_ENT_ADD_USER = 0xE700,
        IMGUI_ICON_ENT_VCARD = 0xE722,
        IMGUI_ICON_ENT_EXPORT = 0xE715,
        IMGUI_ICON_ENT_LOCATION = 0xE724,
        IMGUI_ICON_ENT_MAP = 0xE727,
        IMGUI_ICON_ENT_COMPASS = 0xE728,
        IMGUI_ICON_ENT_DIRECTION = 0x27A2,
        IMGUI_ICON_ENT_HAIR_CROSS = 0x1F3AF,
        IMGUI_ICON_ENT_SHARE = 0xE73C,
        IMGUI_ICON_ENT_SHAREABLE = 0xE73E,
        IMGUI_ICON_ENT_HEART = 0x2665,
        IMGUI_ICON_ENT_HEART_EMPTY = 0x2661,
        IMGUI_ICON_ENT_STAR = 0x2605,
        IMGUI_ICON_ENT_STAR_EMPTY = 0x2606,
        IMGUI_ICON_ENT_THUMBS_UP = 0x1F44D,
        IMGUI_ICON_ENT_THUMBS_DOWN = 0x1F44E,
        IMGUI_ICON_ENT_CHAT = 0xE720,
        IMGUI_ICON_ENT_COMMENT = 0xE718,
        IMGUI_ICON_ENT_QUOTE = 0x275E,
        IMGUI_ICON_ENT_HOME = 0x2302,
        IMGUI_ICON_ENT_POPUP = 0xE74C,
        IMGUI_ICON_ENT_SEARCH = 0x1F50D,
        IMGUI_ICON_ENT_FLASHLIGHT = 0x1F526,
        IMGUI_ICON_ENT_PRINT = 0xE716,
        IMGUI_ICON_ENT_BELL = 0x1F514,
        IMGUI_ICON_ENT_LINK = 0x1F517,
        IMGUI_ICON_ENT_FLAG = 0x2691,
        IMGUI_ICON_ENT_COG = 0x2699,
        IMGUI_ICON_ENT_TOOLS = 0x2692,
        IMGUI_ICON_ENT_TROPHY = 0x1F3C6,
        IMGUI_ICON_ENT_TAG = 0xE70C,
        IMGUI_ICON_ENT_CAMERA = 0x1F4F7,
        IMGUI_ICON_ENT_MEGAPHONE = 0x1F4E3,
        IMGUI_ICON_ENT_MOON = 0x263D,
        IMGUI_ICON_ENT_PALETTE = 0x1F3A8,
        IMGUI_ICON_ENT_LEAF = 0x1F342,
        IMGUI_ICON_ENT_NOTE = 0x266A,
        IMGUI_ICON_ENT_BEAMED_NOTE = 0x266B,
        IMGUI_ICON_ENT_NEW = 0x1F4A5,
        IMGUI_ICON_ENT_GRADUATION_CAP = 0x1F393,
        IMGUI_ICON_ENT_BOOK = 0x1F4D5,
        IMGUI_ICON_ENT_NEWSPAPER = 0x1F4F0,
        IMGUI_ICON_ENT_BAG = 0x1F45C,
        IMGUI_ICON_ENT_AIRPLANE = 0x2708,
        IMGUI_ICON_ENT_LIFEBUOY = 0xE788,
        IMGUI_ICON_ENT_EYE = 0xE70A,
        IMGUI_ICON_ENT_CLOCK = 0x1F554,
        IMGUI_ICON_ENT_MIC = 0x1F3A4,
        IMGUI_ICON_ENT_CALENDAR = 0x1F4C5,
        IMGUI_ICON_ENT_FLASH = 0x26A1,
        IMGUI_ICON_ENT_THUNDER_CLOUD = 0x26C8,
        IMGUI_ICON_ENT_DROPLET = 0x1F4A7,
        IMGUI_ICON_ENT_CD = 0x1F4BF,
        IMGUI_ICON_ENT_BRIEFCASE = 0x1F4BC,
        IMGUI_ICON_ENT_AIR = 0x1F4A8,
        IMGUI_ICON_ENT_HOURGLASS = 0x23F3,
        IMGUI_ICON_ENT_GAUGE = 0x1F6C7,
        IMGUI_ICON_ENT_LANGUAGE = 0x1F394,
        IMGUI_ICON_ENT_NETWORK = 0xE776,
        IMGUI_ICON_ENT_KEY = 0x1F511,
        IMGUI_ICON_ENT_BATTERY = 0x1F50B,
        IMGUI_ICON_ENT_BUCKET = 0x1F4FE,
        IMGUI_ICON_ENT_MAGNET = 0xE7A1,
        IMGUI_ICON_ENT_DRIVE = 0x1F4FD,
        IMGUI_ICON_ENT_CUP = 0x2615,
        IMGUI_ICON_ENT_ROCKET = 0x1F680,
        IMGUI_ICON_ENT_BRUSH = 0xE79A,
        IMGUI_ICON_ENT_SUITCASE = 0x1F6C6,
        IMGUI_ICON_ENT_TRAFFIC_CONE = 0x1F6C8,
        IMGUI_ICON_ENT_GLOBE = 0x1F30E,
        IMGUI_ICON_ENT_KEYBOARD = 0x2328,
        IMGUI_ICON_ENT_BROWSER = 0xE74E,
        IMGUI_ICON_ENT_PUBLISH = 0xE74D,
        IMGUI_ICON_ENT_PROGRESS_3 = 0xE76B,
        IMGUI_ICON_ENT_PROGRESS_2 = 0xE76A,
        IMGUI_ICON_ENT_PROGRESS_1 = 0xE769,
        IMGUI_ICON_ENT_PROGRESS_0 = 0xE768,
        IMGUI_ICON_ENT_LIGHT_DOWN = 0x1F505,
        IMGUI_ICON_ENT_LIGHT_UP = 0x1F506,
        IMGUI_ICON_ENT_ADJUST = 0x25D1,
        IMGUI_ICON_ENT_CODE = 0xE714,
        IMGUI_ICON_ENT_MONITOR = 0x1F4BB,
        IMGUI_ICON_ENT_INFINITY = 0x221E,
        IMGUI_ICON_ENT_LIGHT_BULB = 0x1F4A1,
        IMGUI_ICON_ENT_CREDIT_CARD = 0x1F4B3,
        IMGUI_ICON_ENT_DATABASE = 0x1F4F8,
        IMGUI_ICON_ENT_VOICEMAIL = 0x2707,
        IMGUI_ICON_ENT_CLIPBOARD = 0x1F4CB,
        IMGUI_ICON_ENT_CART = 0xE73D,
        IMGUI_ICON_ENT_BOX = 0x1F4E6,
        IMGUI_ICON_ENT_TICKET = 0x1F3AB,
        IMGUI_ICON_ENT_RSS = 0xE73A,
        IMGUI_ICON_ENT_SIGNAL = 0x1F4F6,
        IMGUI_ICON_ENT_THERMOMETER = 0x1F4FF,
        IMGUI_ICON_ENT_WATER = 0x1F4A6,
        IMGUI_ICON_ENT_SWEDEN = 0xF601,
        IMGUI_ICON_ENT_LINE_GRAPH = 0x1F4C8,
        IMGUI_ICON_ENT_PIE_CHART = 0x25F4,
        IMGUI_ICON_ENT_BAR_GRAPH = 0x1F4CA,
        IMGUI_ICON_ENT_AREA_GRAPH = 0x1F53E,
        IMGUI_ICON_ENT_LOCK = 0x1F512,
        IMGUI_ICON_ENT_LOCK_OPEN = 0x1F513,
        IMGUI_ICON_ENT_LOGOUT = 0xE741,
        IMGUI_ICON_ENT_LOGIN = 0xE740,
        IMGUI_ICON_ENT_CHECK = 0x2713,
        IMGUI_ICON_ENT_CROSS = 0x274C,
        IMGUI_ICON_ENT_SQUARED_MINUS = 0x229F,
        IMGUI_ICON_ENT_SQUARED_PLUS = 0x229E,
        IMGUI_ICON_ENT_SQUARED_CROSS = 0x274E,
        IMGUI_ICON_ENT_CIRCLED_MINUS = 0x2296,
        IMGUI_ICON_ENT_CIRCLED_PLUS = 0x2295,
        IMGUI_ICON_ENT_CIRCLED_CROSS = 0x2716,
        IMGUI_ICON_ENT_MINUS = 0x2796,
        IMGUI_ICON_ENT_PLUS = 0x2795,
        IMGUI_ICON_ENT_ERASE = 0x232B,
        IMGUI_ICON_ENT_BLOCK = 0x1F6AB,
        IMGUI_ICON_ENT_INFO = 0x2139,
        IMGUI_ICON_ENT_CIRCLED_INFO = 0xE705,
        IMGUI_ICON_ENT_HELP = 0x2753,
        IMGUI_ICON_ENT_CIRCLED_HELP = 0xE704,
        IMGUI_ICON_ENT_WARNING = 0x26A0,
        IMGUI_ICON_ENT_CYCLE = 0x1F504,
        IMGUI_ICON_ENT_CW = 0x27F3,
        IMGUI_ICON_ENT_CCW = 0x27F2,
        IMGUI_ICON_ENT_SHUFFLE = 0x1F500,
        IMGUI_ICON_ENT_BACK = 0x1F519,
        IMGUI_ICON_ENT_LEVEL_DOWN = 0x21B3,
        IMGUI_ICON_ENT_RETWEET = 0xE717,
        IMGUI_ICON_ENT_LOOP = 0x1F501,
        IMGUI_ICON_ENT_BACK_IN_TIME = 0xE771,
        IMGUI_ICON_ENT_LEVEL_UP = 0x21B0,
        IMGUI_ICON_ENT_SWITCH = 0x21C6,
        IMGUI_ICON_ENT_NUMBERED_LIST = 0xE005,
        IMGUI_ICON_ENT_ADD_TO_LIST = 0xE003,
        IMGUI_ICON_ENT_LAYOUT = 0x268F,
        IMGUI_ICON_ENT_LIST = 0x2630,
        IMGUI_ICON_ENT_TEXT_DOC = 0x1F4C4,
        IMGUI_ICON_ENT_TEXT_DOC_INVERTED = 0xE731,
        IMGUI_ICON_ENT_DOC = 0xE730,
        IMGUI_ICON_ENT_DOCS = 0xE736,
        IMGUI_ICON_ENT_LANDSCAPE_DOC = 0xE737,
        IMGUI_ICON_ENT_PICTURE = 0x1F304,
        IMGUI_ICON_ENT_VIDEO = 0x1F3AC,
        IMGUI_ICON_ENT_MUSIC = 0x1F3B5,
        IMGUI_ICON_ENT_FOLDER = 0x1F4C1,
        IMGUI_ICON_ENT_ARCHIVE = 0xE800,
        IMGUI_ICON_ENT_TRASH = 0xE729,
        IMGUI_ICON_ENT_UPLOAD = 0x1F4E4,
        IMGUI_ICON_ENT_DOWNLOAD = 0x1F4E5,
        IMGUI_ICON_ENT_SAVE = 0x1F4BE,
        IMGUI_ICON_ENT_INSTALL = 0xE778,
        IMGUI_ICON_ENT_CLOUD = 0x2601,
        IMGUI_ICON_ENT_UPLOAD_CLOUD = 0xE711,
        IMGUI_ICON_ENT_BOOKMARK = 0x1F516,
        IMGUI_ICON_ENT_BOOKMARKS = 0x1F4D1,
        IMGUI_ICON_ENT_OPEN_BOOK = 0x1F4D6,
        IMGUI_ICON_ENT_PLAY = 0x25B6,
        IMGUI_ICON_ENT_PAUSE = 0x2016,
        IMGUI_ICON_ENT_RECORD = 0x25CF,
        IMGUI_ICON_ENT_STOP = 0x25A0,
        IMGUI_ICON_ENT_FF = 0x23E9,
        IMGUI_ICON_ENT_FB = 0x23EA,
        IMGUI_ICON_ENT_TO_START = 0x23EE,
        IMGUI_ICON_ENT_TO_END = 0x23ED,
        IMGUI_ICON_ENT_RESIZE_FULL = 0xE744,
        IMGUI_ICON_ENT_RESIZE_SMALL = 0xE746,
        IMGUI_ICON_ENT_VOLUME = 0x23F7,
        IMGUI_ICON_ENT_SOUND = 0x1F50A,
        IMGUI_ICON_ENT_MUTE = 0x1F507,
        IMGUI_ICON_ENT_FLOW_CASCADE = 0x1F568,
        IMGUI_ICON_ENT_FLOW_BRANCH = 0x1F569,
        IMGUI_ICON_ENT_FLOW_TREE = 0x1F56A,
        IMGUI_ICON_ENT_FLOW_LINE = 0x1F56B,
        IMGUI_ICON_ENT_FLOW_PARALLEL = 0x1F56C,
        IMGUI_ICON_ENT_LEFT_BOLD = 0xE4AD,
        IMGUI_ICON_ENT_DOWN_BOLD = 0xE4B0,
        IMGUI_ICON_ENT_UP_BOLD = 0xE4AF,
        IMGUI_ICON_ENT_RIGHT_BOLD = 0xE4AE,
        IMGUI_ICON_ENT_LEFT = 0x2B05,
        IMGUI_ICON_ENT_DOWN = 0x2B07,
        IMGUI_ICON_ENT_UP = 0x2B06,
        IMGUI_ICON_ENT_RIGHT = 0x27A1,
        IMGUI_ICON_ENT_CIRCLED_LEFT = 0xE759,
        IMGUI_ICON_ENT_CIRCLED_DOWN = 0xE758,
        IMGUI_ICON_ENT_CIRCLED_UP = 0xE75B,
        IMGUI_ICON_ENT_CIRCLED_RIGHT = 0xE75A,
        IMGUI_ICON_ENT_TRIANGLE_LEFT = 0x25C2,
        IMGUI_ICON_ENT_TRIANGLE_DOWN = 0x25BE,
        IMGUI_ICON_ENT_TRIANGLE_UP = 0x25B4,
        IMGUI_ICON_ENT_TRIANGLE_RIGHT = 0x25B8,
        IMGUI_ICON_ENT_CHEVRON_LEFT = 0xE75D,
        IMGUI_ICON_ENT_CHEVRON_DOWN = 0xE75C,
        IMGUI_ICON_ENT_CHEVRON_UP = 0xE75F,
        IMGUI_ICON_ENT_CHEVRON_RIGHT = 0xE75E,
        IMGUI_ICON_ENT_CHEVRON_SMALL_LEFT = 0xE761,
        IMGUI_ICON_ENT_CHEVRON_SMALL_DOWN = 0xE760,
        IMGUI_ICON_ENT_CHEVRON_SMALL_UP = 0xE763,
        IMGUI_ICON_ENT_CHEVRON_SMALL_RIGHT = 0xE762,
        IMGUI_ICON_ENT_CHEVRON_THIN_LEFT = 0xE765,
        IMGUI_ICON_ENT_CHEVRON_THIN_DOWN = 0xE764,
        IMGUI_ICON_ENT_CHEVRON_THIN_UP = 0xE767,
        IMGUI_ICON_ENT_CHEVRON_THIN_RIGHT = 0xE766,
        IMGUI_ICON_ENT_LEFT_THIN = 0x2190,
        IMGUI_ICON_ENT_DOWN_THIN = 0x2193,
        IMGUI_ICON_ENT_UP_THIN = 0x2191,
        IMGUI_ICON_ENT_RIGHT_THIN = 0x2192,
        IMGUI_ICON_ENT_ARROW_COMBO = 0xE74F,
        IMGUI_ICON_ENT_THREE_DOTS = 0x23F6,
        IMGUI_ICON_ENT_TWO_DOTS = 0x23F5,
        IMGUI_ICON_ENT_DOT = 0x23F4,
        IMGUI_ICON_ENT_CC = 0x1F545,
        IMGUI_ICON_ENT_CC_BY = 0x1F546,
        IMGUI_ICON_ENT_CC_NC = 0x1F547,
        IMGUI_ICON_ENT_CC_NC_EU = 0x1F548,
        IMGUI_ICON_ENT_CC_NC_JP = 0x1F549,
        IMGUI_ICON_ENT_CC_SA = 0x1F54A,
        IMGUI_ICON_ENT_CC_ND = 0x1F54B,
        IMGUI_ICON_ENT_CC_PD = 0x1F54C,
        IMGUI_ICON_ENT_CC_ZERO = 0x1F54D,
        IMGUI_ICON_ENT_CC_SHARE = 0x1F54E,
        IMGUI_ICON_ENT_CC_REMIX = 0x1F54F,
        IMGUI_ICON_ENT_DB_LOGO = 0x1F5F9,
        IMGUI_ICON_ENT_DB_SHAPE = 0x1F5FA
};

// built-in icons (http://fontawesome.io/)

enum {
        IMGUI_ICON_FA_GLASS = 0xF000,
        IMGUI_ICON_FA_MUSIC = 0xF001,
        IMGUI_ICON_FA_SEARCH = 0xF002,
        IMGUI_ICON_FA_ENVELOPE_O = 0xF003,
        IMGUI_ICON_FA_HEART = 0xF004,
        IMGUI_ICON_FA_STAR = 0xF005,
        IMGUI_ICON_FA_STAR_O = 0xF006,
        IMGUI_ICON_FA_USER = 0xF007,
        IMGUI_ICON_FA_FILM = 0xF008,
        IMGUI_ICON_FA_TH_LARGE = 0xF009,
        IMGUI_ICON_FA_TH = 0xF00A,
        IMGUI_ICON_FA_TH_LIST = 0xF00B,
        IMGUI_ICON_FA_CHECK = 0xF00C,
        IMGUI_ICON_FA_TIMES = 0xF00D,
        IMGUI_ICON_FA_SEARCH_PLUS = 0xF00E,
        IMGUI_ICON_FA_SEARCH_MINUS = 0xF010,
        IMGUI_ICON_FA_POWER_OFF = 0xF011,
        IMGUI_ICON_FA_SIGNAL = 0xF012,
        IMGUI_ICON_FA_GEAR = 0xF013,
        IMGUI_ICON_FA_COG = 0xF013,
        IMGUI_ICON_FA_TRASH_O = 0xF014,
        IMGUI_ICON_FA_HOME = 0xF015,
        IMGUI_ICON_FA_FILE_O = 0xF016,
        IMGUI_ICON_FA_CLOCK_O = 0xF017,
        IMGUI_ICON_FA_ROAD = 0xF018,
        IMGUI_ICON_FA_DOWNLOAD = 0xF019,
        IMGUI_ICON_FA_ARROW_CIRCLE_O_DOWN = 0xF01A,
        IMGUI_ICON_FA_ARROW_CIRCLE_O_UP = 0xF01B,
        IMGUI_ICON_FA_INBOX = 0xF01C,
        IMGUI_ICON_FA_PLAY_CIRCLE_O = 0xF01D,
        IMGUI_ICON_FA_ROTATE_RIGHT = 0xF01E,
        IMGUI_ICON_FA_REPEAT = 0xF01E,
        IMGUI_ICON_FA_REFRESH = 0xF021,
        IMGUI_ICON_FA_LIST_ALT = 0xF022,
        IMGUI_ICON_FA_LOCK = 0xF023,
        IMGUI_ICON_FA_FLAG = 0xF024,
        IMGUI_ICON_FA_HEADPHONES = 0xF025,
        IMGUI_ICON_FA_VOLUME_OFF = 0xF026,
        IMGUI_ICON_FA_VOLUME_DOWN = 0xF027,
        IMGUI_ICON_FA_VOLUME_UP = 0xF028,
        IMGUI_ICON_FA_QRCODE = 0xF029,
        IMGUI_ICON_FA_BARCODE = 0xF02A,
        IMGUI_ICON_FA_TAG = 0xF02B,
        IMGUI_ICON_FA_TAGS = 0xF02C,
        IMGUI_ICON_FA_BOOK = 0xF02D,
        IMGUI_ICON_FA_BOOKMARK = 0xF02E,
        IMGUI_ICON_FA_PRINT = 0xF02F,
        IMGUI_ICON_FA_CAMERA = 0xF030,
        IMGUI_ICON_FA_FONT = 0xF031,
        IMGUI_ICON_FA_BOLD = 0xF032,
        IMGUI_ICON_FA_ITALIC = 0xF033,
        IMGUI_ICON_FA_TEXT_HEIGHT = 0xF034,
        IMGUI_ICON_FA_TEXT_WIDTH = 0xF035,
        IMGUI_ICON_FA_ALIGN_LEFT = 0xF036,
        IMGUI_ICON_FA_ALIGN_CENTER = 0xF037,
        IMGUI_ICON_FA_ALIGN_RIGHT = 0xF038,
        IMGUI_ICON_FA_ALIGN_JUSTIFY = 0xF039,
        IMGUI_ICON_FA_LIST = 0xF03A,
        IMGUI_ICON_FA_DEDENT = 0xF03B,
        IMGUI_ICON_FA_OUTDENT = 0xF03B,
        IMGUI_ICON_FA_INDENT = 0xF03C,
        IMGUI_ICON_FA_VIDEO_CAMERA = 0xF03D,
        IMGUI_ICON_FA_PICTURE_O = 0xF03E,
        IMGUI_ICON_FA_PENCIL = 0xF040,
        IMGUI_ICON_FA_MAP_MARKER = 0xF041,
        IMGUI_ICON_FA_ADJUST = 0xF042,
        IMGUI_ICON_FA_TINT = 0xF043,
        IMGUI_ICON_FA_EDIT = 0xF044,
        IMGUI_ICON_FA_PENCIL_SQUARE_O = 0xF044,
        IMGUI_ICON_FA_SHARE_SQUARE_O = 0xF045,
        IMGUI_ICON_FA_CHECK_SQUARE_O = 0xF046,
        IMGUI_ICON_FA_ARROWS = 0xF047,
        IMGUI_ICON_FA_STEP_BACKWARD = 0xF048,
        IMGUI_ICON_FA_FAST_BACKWARD = 0xF049,
        IMGUI_ICON_FA_BACKWARD = 0xF04A,
        IMGUI_ICON_FA_PLAY = 0xF04B,
        IMGUI_ICON_FA_PAUSE = 0xF04C,
        IMGUI_ICON_FA_STOP = 0xF04D,
        IMGUI_ICON_FA_FORWARD = 0xF04E,
        IMGUI_ICON_FA_FAST_FORWARD = 0xF050,
        IMGUI_ICON_FA_STEP_FORWARD = 0xF051,
        IMGUI_ICON_FA_EJECT = 0xF052,
        IMGUI_ICON_FA_CHEVRON_LEFT = 0xF053,
        IMGUI_ICON_FA_CHEVRON_RIGHT = 0xF054,
        IMGUI_ICON_FA_PLUS_CIRCLE = 0xF055,
        IMGUI_ICON_FA_MINUS_CIRCLE = 0xF056,
        IMGUI_ICON_FA_TIMES_CIRCLE = 0xF057,
        IMGUI_ICON_FA_CHECK_CIRCLE = 0xF058,
        IMGUI_ICON_FA_QUESTION_CIRCLE = 0xF059,
        IMGUI_ICON_FA_INFO_CIRCLE = 0xF05A,
        IMGUI_ICON_FA_CROSSHAIRS = 0xF05B,
        IMGUI_ICON_FA_TIMES_CIRCLE_O = 0xF05C,
        IMGUI_ICON_FA_CHECK_CIRCLE_O = 0xF05D,
        IMGUI_ICON_FA_BAN = 0xF05E,
        IMGUI_ICON_FA_ARROW_LEFT = 0xF060,
        IMGUI_ICON_FA_ARROW_RIGHT = 0xF061,
        IMGUI_ICON_FA_ARROW_UP = 0xF062,
        IMGUI_ICON_FA_ARROW_DOWN = 0xF063,
        IMGUI_ICON_FA_MAIL_FORWARD = 0xF064,
        IMGUI_ICON_FA_SHARE = 0xF064,
        IMGUI_ICON_FA_EXPAND = 0xF065,
        IMGUI_ICON_FA_COMPRESS = 0xF066,
        IMGUI_ICON_FA_PLUS = 0xF067,
        IMGUI_ICON_FA_MINUS = 0xF068,
        IMGUI_ICON_FA_ASTERISK = 0xF069,
        IMGUI_ICON_FA_EXCLAMATION_CIRCLE = 0xF06A,
        IMGUI_ICON_FA_GIFT = 0xF06B,
        IMGUI_ICON_FA_LEAF = 0xF06C,
        IMGUI_ICON_FA_FIRE = 0xF06D,
        IMGUI_ICON_FA_EYE = 0xF06E,
        IMGUI_ICON_FA_EYE_SLASH = 0xF070,
        IMGUI_ICON_FA_WARNING = 0xF071,
        IMGUI_ICON_FA_EXCLAMATION_TRIANGLE = 0xF071,
        IMGUI_ICON_FA_PLANE = 0xF072,
        IMGUI_ICON_FA_CALENDAR = 0xF073,
        IMGUI_ICON_FA_RANDOM = 0xF074,
        IMGUI_ICON_FA_COMMENT = 0xF075,
        IMGUI_ICON_FA_MAGNET = 0xF076,
        IMGUI_ICON_FA_CHEVRON_UP = 0xF077,
        IMGUI_ICON_FA_CHEVRON_DOWN = 0xF078,
        IMGUI_ICON_FA_RETWEET = 0xF079,
        IMGUI_ICON_FA_SHOPPING_CART = 0xF07A,
        IMGUI_ICON_FA_FOLDER = 0xF07B,
        IMGUI_ICON_FA_FOLDER_OPEN = 0xF07C,
        IMGUI_ICON_FA_ARROWS_V = 0xF07D,
        IMGUI_ICON_FA_ARROWS_H = 0xF07E,
        IMGUI_ICON_FA_BAR_CHART_O = 0xF080,
        IMGUI_ICON_FA_TWITTER_SQUARE = 0xF081,
        IMGUI_ICON_FA_FACEBOOK_SQUARE = 0xF082,
        IMGUI_ICON_FA_CAMERA_RETRO = 0xF083,
        IMGUI_ICON_FA_KEY = 0xF084,
        IMGUI_ICON_FA_GEARS = 0xF085,
        IMGUI_ICON_FA_COGS = 0xF085,
        IMGUI_ICON_FA_COMMENTS = 0xF086,
        IMGUI_ICON_FA_THUMBS_O_UP = 0xF087,
        IMGUI_ICON_FA_THUMBS_O_DOWN = 0xF088,
        IMGUI_ICON_FA_STAR_HALF = 0xF089,
        IMGUI_ICON_FA_HEART_O = 0xF08A,
        IMGUI_ICON_FA_SIGN_OUT = 0xF08B,
        IMGUI_ICON_FA_LINKEDIN_SQUARE = 0xF08C,
        IMGUI_ICON_FA_THUMB_TACK = 0xF08D,
        IMGUI_ICON_FA_EXTERNAL_LINK = 0xF08E,
        IMGUI_ICON_FA_SIGN_IN = 0xF090,
        IMGUI_ICON_FA_TROPHY = 0xF091,
        IMGUI_ICON_FA_GITHUB_SQUARE = 0xF092,
        IMGUI_ICON_FA_UPLOAD = 0xF093,
        IMGUI_ICON_FA_LEMON_O = 0xF094,
        IMGUI_ICON_FA_PHONE = 0xF095,
        IMGUI_ICON_FA_SQUARE_O = 0xF096,
        IMGUI_ICON_FA_BOOKMARK_O = 0xF097,
        IMGUI_ICON_FA_PHONE_SQUARE = 0xF098,
        IMGUI_ICON_FA_TWITTER = 0xF099,
        IMGUI_ICON_FA_FACEBOOK = 0xF09A,
        IMGUI_ICON_FA_GITHUB = 0xF09B,
        IMGUI_ICON_FA_UNLOCK = 0xF09C,
        IMGUI_ICON_FA_CREDIT_CARD = 0xF09D,
        IMGUI_ICON_FA_RSS = 0xF09E,
        IMGUI_ICON_FA_HDD_O = 0xF0A0,
        IMGUI_ICON_FA_BULLHORN = 0xF0A1,
        IMGUI_ICON_FA_BELL = 0xF0F3,
        IMGUI_ICON_FA_CERTIFICATE = 0xF0A3,
        IMGUI_ICON_FA_HAND_O_RIGHT = 0xF0A4,
        IMGUI_ICON_FA_HAND_O_LEFT = 0xF0A5,
        IMGUI_ICON_FA_HAND_O_UP = 0xF0A6,
        IMGUI_ICON_FA_HAND_O_DOWN = 0xF0A7,
        IMGUI_ICON_FA_ARROW_CIRCLE_LEFT = 0xF0A8,
        IMGUI_ICON_FA_ARROW_CIRCLE_RIGHT = 0xF0A9,
        IMGUI_ICON_FA_ARROW_CIRCLE_UP = 0xF0AA,
        IMGUI_ICON_FA_ARROW_CIRCLE_DOWN = 0xF0AB,
        IMGUI_ICON_FA_GLOBE = 0xF0AC,
        IMGUI_ICON_FA_WRENCH = 0xF0AD,
        IMGUI_ICON_FA_TASKS = 0xF0AE,
        IMGUI_ICON_FA_FILTER = 0xF0B0,
        IMGUI_ICON_FA_BRIEFCASE = 0xF0B1,
        IMGUI_ICON_FA_ARROWS_ALT = 0xF0B2,
        IMGUI_ICON_FA_GROUP = 0xF0C0,
        IMGUI_ICON_FA_USERS = 0xF0C0,
        IMGUI_ICON_FA_CHAIN = 0xF0C1,
        IMGUI_ICON_FA_LINK = 0xF0C1,
        IMGUI_ICON_FA_CLOUD = 0xF0C2,
        IMGUI_ICON_FA_FLASK = 0xF0C3,
        IMGUI_ICON_FA_CUT = 0xF0C4,
        IMGUI_ICON_FA_SCISSORS = 0xF0C4,
        IMGUI_ICON_FA_COPY = 0xF0C5,
        IMGUI_ICON_FA_FILES_O = 0xF0C5,
        IMGUI_ICON_FA_PAPERCLIP = 0xF0C6,
        IMGUI_ICON_FA_SAVE = 0xF0C7,
        IMGUI_ICON_FA_FLOPPY_O = 0xF0C7,
        IMGUI_ICON_FA_SQUARE = 0xF0C8,
        IMGUI_ICON_FA_BARS = 0xF0C9,
        IMGUI_ICON_FA_LIST_UL = 0xF0CA,
        IMGUI_ICON_FA_LIST_OL = 0xF0CB,
        IMGUI_ICON_FA_STRIKETHROUGH = 0xF0CC,
        IMGUI_ICON_FA_UNDERLINE = 0xF0CD,
        IMGUI_ICON_FA_TABLE = 0xF0CE,
        IMGUI_ICON_FA_MAGIC = 0xF0D0,
        IMGUI_ICON_FA_TRUCK = 0xF0D1,
        IMGUI_ICON_FA_PINTEREST = 0xF0D2,
        IMGUI_ICON_FA_PINTEREST_SQUARE = 0xF0D3,
        IMGUI_ICON_FA_GOOGLE_PLUS_SQUARE = 0xF0D4,
        IMGUI_ICON_FA_GOOGLE_PLUS = 0xF0D5,
        IMGUI_ICON_FA_MONEY = 0xF0D6,
        IMGUI_ICON_FA_CARET_DOWN = 0xF0D7,
        IMGUI_ICON_FA_CARET_UP = 0xF0D8,
        IMGUI_ICON_FA_CARET_LEFT = 0xF0D9,
        IMGUI_ICON_FA_CARET_RIGHT = 0xF0DA,
        IMGUI_ICON_FA_COLUMNS = 0xF0DB,
        IMGUI_ICON_FA_UNSORTED = 0xF0DC,
        IMGUI_ICON_FA_SORT = 0xF0DC,
        IMGUI_ICON_FA_SORT_DOWN = 0xF0DD,
        IMGUI_ICON_FA_SORT_ASC = 0xF0DD,
        IMGUI_ICON_FA_SORT_UP = 0xF0DE,
        IMGUI_ICON_FA_SORT_DESC = 0xF0DE,
        IMGUI_ICON_FA_ENVELOPE = 0xF0E0,
        IMGUI_ICON_FA_LINKEDIN = 0xF0E1,
        IMGUI_ICON_FA_ROTATE_LEFT = 0xF0E2,
        IMGUI_ICON_FA_UNDO = 0xF0E2,
        IMGUI_ICON_FA_LEGAL = 0xF0E3,
        IMGUI_ICON_FA_GAVEL = 0xF0E3,
        IMGUI_ICON_FA_DASHBOARD = 0xF0E4,
        IMGUI_ICON_FA_TACHOMETER = 0xF0E4,
        IMGUI_ICON_FA_COMMENT_O = 0xF0E5,
        IMGUI_ICON_FA_COMMENTS_O = 0xF0E6,
        IMGUI_ICON_FA_FLASH = 0xF0E7,
        IMGUI_ICON_FA_BOLT = 0xF0E7,
        IMGUI_ICON_FA_SITEMAP = 0xF0E8,
        IMGUI_ICON_FA_UMBRELLA = 0xF0E9,
        IMGUI_ICON_FA_PASTE = 0xF0EA,
        IMGUI_ICON_FA_CLIPBOARD = 0xF0EA,
        IMGUI_ICON_FA_LIGHTBULB_O = 0xF0EB,
        IMGUI_ICON_FA_EXCHANGE = 0xF0EC,
        IMGUI_ICON_FA_CLOUD_DOWNLOAD = 0xF0ED,
        IMGUI_ICON_FA_CLOUD_UPLOAD = 0xF0EE,
        IMGUI_ICON_FA_USER_MD = 0xF0F0,
        IMGUI_ICON_FA_STETHOSCOPE = 0xF0F1,
        IMGUI_ICON_FA_SUITCASE = 0xF0F2,
        IMGUI_ICON_FA_BELL_O = 0xF0A2,
        IMGUI_ICON_FA_COFFEE = 0xF0F4,
        IMGUI_ICON_FA_CUTLERY = 0xF0F5,
        IMGUI_ICON_FA_FILE_TEXT_O = 0xF0F6,
        IMGUI_ICON_FA_BUILDING_O = 0xF0F7,
        IMGUI_ICON_FA_HOSPITAL_O = 0xF0F8,
        IMGUI_ICON_FA_AMBULANCE = 0xF0F9,
        IMGUI_ICON_FA_MEDKIT = 0xF0FA,
        IMGUI_ICON_FA_FIGHTER_JET = 0xF0FB,
        IMGUI_ICON_FA_BEER = 0xF0FC,
        IMGUI_ICON_FA_H_SQUARE = 0xF0FD,
        IMGUI_ICON_FA_PLUS_SQUARE = 0xF0FE,
        IMGUI_ICON_FA_ANGLE_DOUBLE_LEFT = 0xF100,
        IMGUI_ICON_FA_ANGLE_DOUBLE_RIGHT = 0xF101,
        IMGUI_ICON_FA_ANGLE_DOUBLE_UP = 0xF102,
        IMGUI_ICON_FA_ANGLE_DOUBLE_DOWN = 0xF103,
        IMGUI_ICON_FA_ANGLE_LEFT = 0xF104,
        IMGUI_ICON_FA_ANGLE_RIGHT = 0xF105,
        IMGUI_ICON_FA_ANGLE_UP = 0xF106,
        IMGUI_ICON_FA_ANGLE_DOWN = 0xF107,
        IMGUI_ICON_FA_DESKTOP = 0xF108,
        IMGUI_ICON_FA_LAPTOP = 0xF109,
        IMGUI_ICON_FA_TABLET = 0xF10A,
        IMGUI_ICON_FA_MOBILE_PHONE = 0xF10B,
        IMGUI_ICON_FA_MOBILE = 0xF10B,
        IMGUI_ICON_FA_CIRCLE_O = 0xF10C,
        IMGUI_ICON_FA_QUOTE_LEFT = 0xF10D,
        IMGUI_ICON_FA_QUOTE_RIGHT = 0xF10E,
        IMGUI_ICON_FA_SPINNER = 0xF110,
        IMGUI_ICON_FA_CIRCLE = 0xF111,
        IMGUI_ICON_FA_MAIL_REPLY = 0xF112,
        IMGUI_ICON_FA_REPLY = 0xF112,
        IMGUI_ICON_FA_GITHUB_ALT = 0xF113,
        IMGUI_ICON_FA_FOLDER_O = 0xF114,
        IMGUI_ICON_FA_FOLDER_OPEN_O = 0xF115,
        IMGUI_ICON_FA_SMILE_O = 0xF118,
        IMGUI_ICON_FA_FROWN_O = 0xF119,
        IMGUI_ICON_FA_MEH_O = 0xF11A,
        IMGUI_ICON_FA_GAMEPAD = 0xF11B,
        IMGUI_ICON_FA_KEYBOARD_O = 0xF11C,
        IMGUI_ICON_FA_FLAG_O = 0xF11D,
        IMGUI_ICON_FA_FLAG_CHECKERED = 0xF11E,
        IMGUI_ICON_FA_TERMINAL = 0xF120,
        IMGUI_ICON_FA_CODE = 0xF121,
        IMGUI_ICON_FA_REPLY_ALL = 0xF122,
        IMGUI_ICON_FA_MAIL_REPLY_ALL = 0xF122,
        IMGUI_ICON_FA_STAR_HALF_EMPTY = 0xF123,
        IMGUI_ICON_FA_STAR_HALF_FULL = 0xF123,
        IMGUI_ICON_FA_STAR_HALF_O = 0xF123,
        IMGUI_ICON_FA_LOCATION_ARROW = 0xF124,
        IMGUI_ICON_FA_CROP = 0xF125,
        IMGUI_ICON_FA_CODE_FORK = 0xF126,
        IMGUI_ICON_FA_UNLINK = 0xF127,
        IMGUI_ICON_FA_CHAIN_BROKEN = 0xF127,
        IMGUI_ICON_FA_QUESTION = 0xF128,
        IMGUI_ICON_FA_INFO = 0xF129,
        IMGUI_ICON_FA_EXCLAMATION = 0xF12A,
        IMGUI_ICON_FA_SUPERSCRIPT = 0xF12B,
        IMGUI_ICON_FA_SUBSCRIPT = 0xF12C,
        IMGUI_ICON_FA_ERASER = 0xF12D,
        IMGUI_ICON_FA_PUZZLE_PIECE = 0xF12E,
        IMGUI_ICON_FA_MICROPHONE = 0xF130,
        IMGUI_ICON_FA_MICROPHONE_SLASH = 0xF131,
        IMGUI_ICON_FA_SHIELD = 0xF132,
        IMGUI_ICON_FA_CALENDAR_O = 0xF133,
        IMGUI_ICON_FA_FIRE_EXTINGUISHER = 0xF134,
        IMGUI_ICON_FA_ROCKET = 0xF135,
        IMGUI_ICON_FA_MAXCDN = 0xF136,
        IMGUI_ICON_FA_CHEVRON_CIRCLE_LEFT = 0xF137,
        IMGUI_ICON_FA_CHEVRON_CIRCLE_RIGHT = 0xF138,
        IMGUI_ICON_FA_CHEVRON_CIRCLE_UP = 0xF139,
        IMGUI_ICON_FA_CHEVRON_CIRCLE_DOWN = 0xF13A,
        IMGUI_ICON_FA_HTML5 = 0xF13B,
        IMGUI_ICON_FA_CSS3 = 0xF13C,
        IMGUI_ICON_FA_ANCHOR = 0xF13D,
        IMGUI_ICON_FA_UNLOCK_ALT = 0xF13E,
        IMGUI_ICON_FA_BULLSEYE = 0xF140,
        IMGUI_ICON_FA_ELLIPSIS_H = 0xF141,
        IMGUI_ICON_FA_ELLIPSIS_V = 0xF142,
        IMGUI_ICON_FA_RSS_SQUARE = 0xF143,
        IMGUI_ICON_FA_PLAY_CIRCLE = 0xF144,
        IMGUI_ICON_FA_TICKET = 0xF145,
        IMGUI_ICON_FA_MINUS_SQUARE = 0xF146,
        IMGUI_ICON_FA_MINUS_SQUARE_O = 0xF147,
        IMGUI_ICON_FA_LEVEL_UP = 0xF148,
        IMGUI_ICON_FA_LEVEL_DOWN = 0xF149,
        IMGUI_ICON_FA_CHECK_SQUARE = 0xF14A,
        IMGUI_ICON_FA_PENCIL_SQUARE = 0xF14B,
        IMGUI_ICON_FA_EXTERNAL_LINK_SQUARE = 0xF14C,
        IMGUI_ICON_FA_SHARE_SQUARE = 0xF14D,
        IMGUI_ICON_FA_COMPASS = 0xF14E,
        IMGUI_ICON_FA_TOGGLE_DOWN = 0xF150,
        IMGUI_ICON_FA_CARET_SQUARE_O_DOWN = 0xF150,
        IMGUI_ICON_FA_TOGGLE_UP = 0xF151,
        IMGUI_ICON_FA_CARET_SQUARE_O_UP = 0xF151,
        IMGUI_ICON_FA_TOGGLE_RIGHT = 0xF152,
        IMGUI_ICON_FA_CARET_SQUARE_O_RIGHT = 0xF152,
        IMGUI_ICON_FA_EURO = 0xF153,
        IMGUI_ICON_FA_EUR = 0xF153,
        IMGUI_ICON_FA_GBP = 0xF154,
        IMGUI_ICON_FA_DOLLAR = 0xF155,
        IMGUI_ICON_FA_USD = 0xF155,
        IMGUI_ICON_FA_RUPEE = 0xF156,
        IMGUI_ICON_FA_INR = 0xF156,
        IMGUI_ICON_FA_CNY = 0xF157,
        IMGUI_ICON_FA_RMB = 0xF157,
        IMGUI_ICON_FA_YEN = 0xF157,
        IMGUI_ICON_FA_JPY = 0xF157,
        IMGUI_ICON_FA_RUBLE = 0xF158,
        IMGUI_ICON_FA_ROUBLE = 0xF158,
        IMGUI_ICON_FA_RUB = 0xF158,
        IMGUI_ICON_FA_WON = 0xF159,
        IMGUI_ICON_FA_KRW = 0xF159,
        IMGUI_ICON_FA_BITCOIN = 0xF15A,
        IMGUI_ICON_FA_BTC = 0xF15A,
        IMGUI_ICON_FA_FILE = 0xF15B,
        IMGUI_ICON_FA_FILE_TEXT = 0xF15C,
        IMGUI_ICON_FA_SORT_ALPHA_ASC = 0xF15D,
        IMGUI_ICON_FA_SORT_ALPHA_DESC = 0xF15E,
        IMGUI_ICON_FA_SORT_AMOUNT_ASC = 0xF160,
        IMGUI_ICON_FA_SORT_AMOUNT_DESC = 0xF161,
        IMGUI_ICON_FA_SORT_NUMERIC_ASC = 0xF162,
        IMGUI_ICON_FA_SORT_NUMERIC_DESC = 0xF163,
        IMGUI_ICON_FA_THUMBS_UP = 0xF164,
        IMGUI_ICON_FA_THUMBS_DOWN = 0xF165,
        IMGUI_ICON_FA_YOUTUBE_SQUARE = 0xF166,
        IMGUI_ICON_FA_YOUTUBE = 0xF167,
        IMGUI_ICON_FA_XING = 0xF168,
        IMGUI_ICON_FA_XING_SQUARE = 0xF169,
        IMGUI_ICON_FA_YOUTUBE_PLAY = 0xF16A,
        IMGUI_ICON_FA_DROPBOX = 0xF16B,
        IMGUI_ICON_FA_STACK_OVERFLOW = 0xF16C,
        IMGUI_ICON_FA_INSTAGRAM = 0xF16D,
        IMGUI_ICON_FA_FLICKR = 0xF16E,
        IMGUI_ICON_FA_ADN = 0xF170,
        IMGUI_ICON_FA_BITBUCKET = 0xF171,
        IMGUI_ICON_FA_BITBUCKET_SQUARE = 0xF172,
        IMGUI_ICON_FA_TUMBLR = 0xF173,
        IMGUI_ICON_FA_TUMBLR_SQUARE = 0xF174,
        IMGUI_ICON_FA_LONG_ARROW_DOWN = 0xF175,
        IMGUI_ICON_FA_LONG_ARROW_UP = 0xF176,
        IMGUI_ICON_FA_LONG_ARROW_LEFT = 0xF177,
        IMGUI_ICON_FA_LONG_ARROW_RIGHT = 0xF178,
        IMGUI_ICON_FA_APPLE = 0xF179,
        IMGUI_ICON_FA_WINDOWS = 0xF17A,
        IMGUI_ICON_FA_ANDROID = 0xF17B,
        IMGUI_ICON_FA_LINUX = 0xF17C,
        IMGUI_ICON_FA_DRIBBBLE = 0xF17D,
        IMGUI_ICON_FA_SKYPE = 0xF17E,
        IMGUI_ICON_FA_FOURSQUARE = 0xF180,
        IMGUI_ICON_FA_TRELLO = 0xF181,
        IMGUI_ICON_FA_FEMALE = 0xF182,
        IMGUI_ICON_FA_MALE = 0xF183,
        IMGUI_ICON_FA_GITTIP = 0xF184,
        IMGUI_ICON_FA_SUN_O = 0xF185,
        IMGUI_ICON_FA_MOON_O = 0xF186,
        IMGUI_ICON_FA_ARCHIVE = 0xF187,
        IMGUI_ICON_FA_BUG = 0xF188,
        IMGUI_ICON_FA_VK = 0xF189,
        IMGUI_ICON_FA_WEIBO = 0xF18A,
        IMGUI_ICON_FA_RENREN = 0xF18B,
        IMGUI_ICON_FA_PAGELINES = 0xF18C,
        IMGUI_ICON_FA_STACK_EXCHANGE = 0xF18D,
        IMGUI_ICON_FA_ARROW_CIRCLE_O_RIGHT = 0xF18E,
        IMGUI_ICON_FA_ARROW_CIRCLE_O_LEFT = 0xF190,
        IMGUI_ICON_FA_TOGGLE_LEFT = 0xF191,
        IMGUI_ICON_FA_CARET_SQUARE_O_LEFT = 0xF191,
        IMGUI_ICON_FA_DOT_CIRCLE_O = 0xF192,
        IMGUI_ICON_FA_WHEELCHAIR = 0xF193,
        IMGUI_ICON_FA_VIMEO_SQUARE = 0xF194,
        IMGUI_ICON_FA_TURKISH_LIRA = 0xF195,
        IMGUI_ICON_FA_TRY = 0xF195,
        IMGUI_ICON_FA_PLUS_SQUARE_O = 0xF196
};

// tweens
void imguiTween( unsigned mode );

enum {
        IMGUI_TWEEN_LINEAR_01,
        IMGUI_TWEEN_SIN2PI_00,
        IMGUI_TWEEN_SINPI_00,
        IMGUI_TWEEN_SINPI2PI_10,
        IMGUI_TWEEN_SIN4PI_00,
        IMGUI_TWEEN_SIN3PI4_00,
        IMGUI_TWEEN_SINPI2_01,
        IMGUI_TWEEN_ACELBREAK_01,
        IMGUI_TWEEN_COS2PI_11,
        IMGUI_TWEEN_BACKIN_01,
        IMGUI_TWEEN_BACKOUT_01,
        IMGUI_TWEEN_BACKINOUT_01,
        IMGUI_TWEEN_BOUNCEIN_01,
        IMGUI_TWEEN_BOUNCEOUT_01,
        IMGUI_TWEEN_BOUNCEINOUT_01,
        IMGUI_TWEEN_CIRCIN_01,
        IMGUI_TWEEN_CIRCOUT_01,
        IMGUI_TWEEN_CIRCINOUT_01,
        IMGUI_TWEEN_ELASTICIN_01,
        IMGUI_TWEEN_ELASTICOUT_01,
        IMGUI_TWEEN_ELASTICINOUT_01,
        IMGUI_TWEEN_EXPOIN_01,
        IMGUI_TWEEN_EXPOOUT_01,
        IMGUI_TWEEN_EXPOINOUT_01,
        IMGUI_TWEEN_QUADIN_01,
        IMGUI_TWEEN_QUADOUT_01,
        IMGUI_TWEEN_QUADINOUT_01,
        IMGUI_TWEEN_CUBICIN_01,
        IMGUI_TWEEN_CUBICOUT_01,
        IMGUI_TWEEN_CUBICINOUT_01,
        IMGUI_TWEEN_QUARTIN_01,
        IMGUI_TWEEN_QUARTOUT_01,
        IMGUI_TWEEN_QUARTINOUT_01,
        IMGUI_TWEEN_QUINTIN_01,
        IMGUI_TWEEN_QUINTOUT_01,
        IMGUI_TWEEN_QUINTINOUT_01,
        IMGUI_TWEEN_SINEIN_01,
        IMGUI_TWEEN_SINEOUT_01,
        IMGUI_TWEEN_SINEINOUT_01,
        IMGUI_TWEEN_SINESQUARE,
        IMGUI_TWEEN_EXPONENTIAL,
        IMGUI_TWEEN_SCHUBRING1,
        IMGUI_TWEEN_SCHUBRING2,
        IMGUI_TWEEN_SCHUBRING3,

        IMGUI_TWEEN_TOTAL,
        IMGUI_TWEEN_UNDEFINED
};

// Pull render interface.
enum imguiGfxCmdType
{
        IMGUI_GFXCMD_RECT,
        IMGUI_GFXCMD_TRIANGLE,
        IMGUI_GFXCMD_LINE,
        IMGUI_GFXCMD_TEXT,
        IMGUI_GFXCMD_SCISSOR,
        IMGUI_GFXCMD_ARC,
        IMGUI_GFXCMD_TEXTURE
};

struct imguiGfxRect
{
        short x,y,w,h,r;
};

struct imguiGfxText
{
        short x,y,align;
        const char* text;
};

struct imguiGfxLine
{
        short x0,y0,x1,y1,r;
};

struct imguiGfxArc
{
        short x,y;
        float r,t0,t1,w;
};

struct imguiGfxTexture
{
        short x,y;
        float u,v;
        short id;
};

struct imguiGfxCmd
{
        char type;
        char flags;
        char pad[2];
        unsigned int col;
        union
        {
                imguiGfxLine    line;
                imguiGfxRect    rect;
                imguiGfxText    text;
                imguiGfxArc     arc;
                imguiGfxTexture texture;
        };
};

imguiGfxRect imguiRect( unsigned id );

const imguiGfxCmd* imguiGetRenderQueue();
int imguiGetRenderQueueSize();

#endif // IMGUI_HPP
