int yourmain() {
R[0] = 441;
F23_Time += 1;
Mem[SR + 0] = R[0];
F23_Time += 20 + 1;
print_int(Mem[SR + 0]);
F23_Time += 20;
return F23_Time;
}
