int yourmain() {
    // Stack adjustment
    SR -= 1;

    // i := 441;
    R[1] = 441;
    F23_Time += (1);

    // add 441 to Memory
    Mem[SR+1] = R[1];
    F23_Time += (20+1);

    print_int( Mem[SR] );
    print_string( "\nb = " );
    print_int( Mem[SR] );

    SR += 1;
    return 0;
}