#define MAX(x,y,r) ({ int _x = (x), _y = (y), _r = (r); _x > _y ? (r = _x) : (r = _y); })

// int a = 10;
// int b = 20;
// int c = 0;
// printf(("%i",MAX(a, b, c)));