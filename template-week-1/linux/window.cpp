#include "window.hpp"

Window win;
XEvent ev;
Display *dpy;
GC pen;

window::window(int w, int h):
w(w), h(h) {
	int scr;
	unsigned long black, white;
	XGCValues val;

	dpy = XOpenDisplay(NULL);
	scr = DefaultScreen(dpy);

	black = BlackPixel(dpy, scr);
	white = WhitePixel(dpy, scr);

	// Create a window.
	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
	                          0, 0, w, h,
	                          10, white,
	                          black);
	// Show the window.
	XSelectInput(dpy, win, ExposureMask);
	XMapWindow(dpy, win);

	val.foreground = white;
	val.line_width = 1;
	val.line_style = LineSolid;
	pen = XCreateGC(dpy, win, GCForeground|GCLineWidth|GCLineStyle, &val);
}

void window::draw(int x, int y) {
	XDrawPoint(dpy, win, pen, x, y);
	XSync(dpy, False);
}

void window::loop() {
	while (1) {
		XNextEvent(dpy, &ev);
	}
}
