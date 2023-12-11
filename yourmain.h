int yourmain() {
SR -= 4;
R[1] = 5;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
R[1] = 8;
F23_Time += 1;
Mem[SR + 1] = R[1];
F23_Time += 20 + 1;
R[1] = 10;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
R[1] = 9;
F23_Time += 1;
Mem[SR + 2] = R[1];
F23_Time += 20 + 1;
SR += 4;
return 0;
}
