int a = succ[0], b = succ[succ[0]], length =1;
while( a!=b ){
    a = succ[a];
    b = succ[succ[b]];
}
a = 0;
while (a != b) {
    a = succ[a];
    b = succ[b];
}
b = succ[a];
length = 1;
while (a != b) {
    b = succ[b];
    length++;
}
