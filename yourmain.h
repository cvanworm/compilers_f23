int yourmain() {
SR -= 8;
FR = SR;
FR += 8/2;
F[1] = 12.25;
F23_Time += 2;
FMem[FR + 0] = F[1];
F23_Time += 20 + 2;
F[1] = 3.3333;
F23_Time += 2;
FMem[FR + 2] = F[1];
F23_Time += 20 + 2;
R[1] = 4;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
SR += 8;
return 0;
}
