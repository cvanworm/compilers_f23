int yourmain() {
    // Stack adjustment
    SR -= 8;
    // Set FR to beginning of doubles
    // FR = SR;
    // FR += 4;
    // FR = FR >> 1;
    // i := 441;
    R[1] = 441;
    F23_Time += (1);
    Mem[SR+1] = R[1];
    F23_Time += (20+1);


    // c = 3;
    R[2] = 3;
    F23_Time += (1);
    Mem[SR+2] = R[2];
    F23_Time += (20+1);
    // a = b + c;
    R[1] = Mem[SR+1];
    F23_Time += (1+20);
    R[2] = Mem[SR+2];
    F23_Time += (1+20);
    R[3] = R[1] + R[2];
    F23_Time += (1+1+1+1);
    Mem[SR] = R[3];
    F23_Time += (20+1);
    // y = 3.1415;
    F[1] = 3.1415;
    F23_Time += (2);
    FMem[FR+1] = F[1];
    F23_Time += (20+2);
    // x = y * c;
    R[1] = Mem[SR+2];
    F23_Time += (1+20);
    F[1] = (double)R[1];
    F23_Time += (2+1);
    F[2] = FMem[FR+1];
    F23_Time += (2+1+20);
    F[3] = F[1] * F[2];
    F23_Time += (2+2+2+4);
    FMem[FR] = F[3];
    F23_Time += (20+2);
    // Print results
    
    print_string( "a = " );
    print_int( Mem[SR] );
    print_string( "\nb = " );
    print_int( Mem[SR+1] );
    // print_string( "\nc = " );
    // print_int( Mem[SR+2] );
    // print_string( "\nx = " );
    // print_double( FMem[FR] );
    // print_string( "\nx = " );
    // print_double( FMem[FR+1] );
    // Stack adjustment
    SR += 8;
    return 0;
}