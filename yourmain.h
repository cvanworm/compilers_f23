int yourmain() {
SR -= 2;
FR = SR;
FR += SR/2;
R[1] = 9;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
R[1] = 4;
F23_Time += 1;
Mem[SR + 1] = R[1];
F23_Time += 20 + 1;
R[1] =  9;
F23_Time += 1;
R[2] =  9;
F23_Time += 1;
R[3] =  R[1] == R[2];
F23_Time += 1;
if (R[3] == 1) goto If;
if (R[3] != 1) goto Else;
If: 
print_string("i");
F23_Time += 1;
print_string("i");
F23_Time += 1;
goto EndIf;
Else: 
print_string("h");
F23_Time += 1;
print_string("h");
F23_Time += 1;
goto EndIf;
EndIf: 
SR += 2;
return 0;
}
