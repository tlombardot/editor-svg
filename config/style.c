#include "../config/struct.h"
#include "../components/get.h"
#include <stdio.h>
#include "../utils/windows_user.h"

// Tron neon colors
#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define DIM         "\x1b[2m"

#define RED         "\x1b[91m"
#define GREEN       "\x1b[92m"
#define YELLOW      "\x1b[93m"
#define BLUE        "\x1b[94m"
#define MAGENTA     "\x1b[95m"
#define CYAN        "\x1b[96m"
#define WHITE       "\x1b[97m"



// --- FILL STYLE ---
Style createFillStyle(Style *style) {
    printf(BOLD MAGENTA "◆ FILL COLOR STYLE ◆\n" RESET);
    HeaderLine();

    printf(CYAN "Enter RGB values for fill color (0–255):\n" RESET);

    printf(YELLOW " Red   : " RESET);
    style->RF = getInt(0,255);
    printf(YELLOW " Green : " RESET);
    style->GF = getInt(0,255);
    printf(YELLOW " Blue  : " RESET);
    style->BF = getInt(0,255);

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Fill color set: " RESET MAGENTA "RGB(%d, %d, %d)\n",
            style->RF, style->GF, style->BF);
    printf(msg, 2);
    HeaderLine();
    return *style;
}

Style createStrokeStyle(Style *style) {
    printf(BOLD MAGENTA "◆ STROKE COLOR STYLE ◆\n" RESET);
    HeaderLine();

    printf(CYAN "Enter RGB values for stroke color (0–200):\n" RESET);

    printf(YELLOW " Red   : " RESET);
    style->RS = getInt(0,255);
    printf(YELLOW " Green : " RESET);
    style->GS = getInt(0,255);
    printf(YELLOW " Blue  : " RESET);
    style->BS = getInt(0,255);

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Stroke color set: " RESET MAGENTA "RGB(%d, %d, %d)\n",
            style->RS, style->GS, style->BS);
    printf(msg, 2);
    HeaderLine();
    return *style;
}

Style createAngleStyle(Style *style) {
    printf(BOLD MAGENTA "◆ ANGLE STYLE ◆\n" RESET);
    HeaderLine();

    printf(CYAN "Enter rotation angle (0–360): " RESET);
    style->angle = getInt(0,360);

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Angle set to: " RESET MAGENTA "%d°\n", style->angle);
    printf(msg, 2);
    HeaderLine();
    return *style;
}

Translate createTranslateStyle(Style *style) {
    Translate translate = style->translate;

    printf(BOLD MAGENTA "◆ TRANSLATE STYLE ◆\n" RESET);
    HeaderLine();

    printf(YELLOW " X translation (0–200): " RESET);
    translate.x = getInt(0,200);
    printf(YELLOW " Y translation (0–100): " RESET);
    translate.y = getInt(0,100);

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Translation set: " RESET MAGENTA "(%d, %d)\n", translate.x, translate.y);
    printf(msg, 2);
    HeaderLine();

    style->translate = translate;
    return translate;
}
