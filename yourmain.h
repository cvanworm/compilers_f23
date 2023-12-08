int yourmain() {
SR -= 3;
R[1] = 5;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
R[1] = 8;
F23_Time += 1;
Mem[SR + 1] = R[1];
F23_Time += 20 + 1;
print_int(Mem[SR + 0]);
F23_Time += 20 + 1;
print_int(Mem[SR + 1]);
F23_Time += 20 + 1;
SR += 3;
return 0;
}
