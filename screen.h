#define UNICODE
enum COLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE}; // foreground color
#define bg(c) (c+10)
#define COL 80
#define BAR "\u2590"

// function declarations
void clearScreen(void);
void setColors(short, short);
void resetColors(void);
void barChart(int[]);
