#include <stdio.h>
#include <graphics.h>

int main()

 {
    int gd = DETECT, gm;
    int xc, yc, r;
    int x, y, d;
    
                    // Get center coordinates and radius from user
    printf("Enter center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius: ");
    scanf("%d", &r);
    
                        // Initialize graphics system
    initgraph(&gd, &gm, NULL);
    
                             // Draw circle using Midpoint Circle Algorithm
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y) {
                                // Plot 8 points using symmetry
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        
                                // Update coordinates and decision parameter
        if (d <= 0) {
            x++;
            d += 2*x + 1;
        } else {
            y--;
            x++;
            d += 2*(x - y) + 1;
        }
    }
    
                                // Wait for user to close window
    getch();
    
                                    // Restore original graphics mode
    closegraph();
    
    return 0;
}
