int yourmain() {
SR -= 6;
FR = SR;
FR += SR/2;
F[1] = 3.3;
F23_Time += 2;
FMem[FR + 0] = F[1];
F23_Time += 20 + 2;
F[1] = 3.3;
F23_Time += 2;
FMem[FR + 2] = F[1];
F23_Time += 20 + 2;
print_double(FMem[FR + 2]);
F23_Time += 20;
SR += 6;
return 0;
}
