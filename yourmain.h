int yourmain() {
SR -= 12;
FR = SR;
FR -= 12/2;
R[1] = 5;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
R[1] = 0;
F23_Time += 1;
Mem[SR + 1] = R[1];
F23_Time += 20 + 1;
R[1] = 5;
F23_Time += 1;
Mem[SR + 2] = R[1];
F23_Time += 20 + 1;
R[1] = 0;
F23_Time += 1;
Mem[SR + 3] = R[1];
F23_Time += 20 + 1;
int array = allocate_in_Mem( 4 );
F23_Time += 1;
R[1] = 2;
F23_Time += 1;
Mem[SR + 4] = R[1];
F23_Time += 20 + 1;
R[1] = 5;
F23_Time += 1;
Mem[array+0] = R[1];
F23_Time += 20 + 1;
R[1] = 0;
F23_Time += 1;
Mem[array+1] = R[1];
F23_Time += 20 + 1;
R[1] = 6;
F23_Time += 1;
Mem[array+2] = R[1];
F23_Time += 20 + 1;
print_integer(Mem[array+0]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
print_integer(Mem[array+1]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
print_integer(Mem[array+2]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
While: 
R[1] =  Mem[SR + 1];
F23_Time += 1;
R[2] =  Mem[SR + 0];
F23_Time += 1;
R[3] = R[1] < R[2];
F23_Time += 1;
if (R[3] != 1) goto EndWhile;
print_integer(Mem[SR + 1]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
R[1] = 1;
F23_Time += 1;
Mem[SR + 1] += R[1];
F23_Time += 20 + 1;
goto While;
EndWhile: 
R[1] = 9;
F23_Time += 1;
Mem[SR + 5] = R[1];
F23_Time += 20 + 1;
R[1] = 19;
F23_Time += 1;
Mem[SR + 6] = R[1];
F23_Time += 20 + 1;
R[1] = 9;
F23_Time += 1;
Mem[SR + 7] = R[1];
F23_Time += 20 + 1;
R[1] = 19;
F23_Time += 1;
Mem[SR + 0] = R[1];
F23_Time += 20 + 1;
print_integer(Mem[SR + 7]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
print_integer(Mem[SR + 0]);
F23_Time += 20;
print_string("\n");
F23_Time += 1;
R[1] =  9;
F23_Time += 1;
R[2] =  19;
F23_Time += 1;
R[3] = R[1] < R[2];
F23_Time += 1;
if (R[3] == 1) goto If;
if (R[3] != 1) goto Else;
If: 
print_string("a is smaller or the same");
F23_Time += 1;
goto EndIf;
Else: 
print_string("c is smaller or the same.");
F23_Time += 1;
goto EndIf;
EndIf: 
print_string("\n");
F23_Time += 1;
R[1] = 10;
F23_Time += 1;
Mem[SR + 8] = R[1];
F23_Time += 20 + 1;
R[1] = 0;
F23_Time += 1;
Mem[SR + 9] = R[1];
F23_Time += 20 + 1;
Do: 
R[1] =  Mem[SR + 9];
F23_Time += 1;
R[2] =  Mem[SR + 8];
F23_Time += 1;
R[3] = R[1] <= R[2];
F23_Time += 1;
if (R[3] != 1) goto EndDo;
print_integer(Mem[SR + 9]);
F23_Time += 20;
print_string(" ");
F23_Time += 1;
R[1] = 1;
F23_Time += 1;
Mem[SR + 9] += R[1];
F23_Time += 20 + 1;
goto Do;
EndDo: 
SR += 12;
return 0;
}
