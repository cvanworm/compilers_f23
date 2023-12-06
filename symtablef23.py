class SymbolTable:
    def __init__(self):
        self.scopes = []
        self.integers = 0
        self.doubles = 0
        self.strings = 0

    def new_scope(self):
        """Adds a scope to the symbol table
        --------
        Adds a new list inside of the scopes array
        to represent a new scope
        """
        self.scopes.append([])

    def add(self, token, name, value='', symtype=''):
        """Adds a symbol to the symbol table

        Parameters:
        scope (string): Scope of the symbol
        token (string): Token of the symbol
        name (string): Name of the symbol
        value (string): Value of the symbol
        symtype (string): Type of the symbol

        """
        # create symbol instance
        symbol = Symbol(token, name, value, symtype)

        # check if symbol already exists at scope and update value
        for sym in self.scopes[-1]:
            if sym.name == name:
                if symbol.value == "++":
                    sym.value += 1
                elif symbol.value == "--":
                    sym.value -= 1
                else:
                    sym.value = value
                return
        
        # otherwise add it
        self.scopes[-1].append(symbol)

        # update counts
        if symbol.type == 'integer':
            self.integers += 1
        elif symbol.type == 'double':
            self.doubles += 1
        elif symbol.type == 'string':
            self.strings += 1

    def add_array(self, name, index, value):
        symbol = self.__find_symbol(name)
        if symbol == None:
            return None
        print("arr:", symbol.value)
        symbol.value[index] = value
        print(symbol.value)
    
    def add_mem(self, scope, name, memory):
        symbol = self.__find_symbol(scope, name)
        if symbol == None:
            return None
        symbol.add_mem(memory)

    def get_value(self, scope, name):
        """Finds a symbol in the symbol table

        Parameters:
        scope (string): Scope of the symbol
        name (string): Name of the symbol

        Returns:
        symbol || none:Symbol if found, None otherwise
        
        """
        symbol = self.__find_symbol(scope, name)
        return symbol.get_value() if symbol else None
    
    
    def get_type(self, scope, name):
        """Returns the type of a symbol in the symbol table

        Parameters:
        scope (string): Scope of the symbol
        name (string): Name of the symbol

        Returns:
        symbol.type || None
        """
        symbol = self.__find_symbol(scope, name)
        return symbol.get_type() if symbol else None
    
    def get_mem(self, scope, name):
        """Returns the memory address of a symbol in the symbol table

        Parameters:
        scope (string): Scope of the symbol
        name (string): Name of the symbol

        Returns:
        symbol.memory || None
        """
        symbol = self.__find_symbol(scope, name)
        return symbol.memory if symbol else None

    def print(self):
        print('\n{:=^100}'.format("SYMBOL TABLE"))
        print("\n{:<16}{:<16}{:<16}{:<16}{:<16}{:<16}".format("Scope", "Token", "Name", "Value", "Type", "Memory"))
        for i in range(len(self.scopes)):
            for symbol in self.scopes[i]:
                if type(symbol.value) == list:
                    print("{:<16}{:<16}{:<16}{:<16}{:<16}{:<16}".format(i, str(symbol.token), symbol.name, f"[...]", symbol.type, symbol.memory))
                else:
                    print("{:<16}{:<16}{:<16}{:<16}{:<16}{:<16}".format(i, str(symbol.token), symbol.name, str(symbol.value), symbol.type, symbol.memory))
            print("-"*100)
            
        print()
        self.__get_symbol_stats()
        # print(f"SR offset: {self.get_symbol_counts()}")
        print("="*100)

    def __find_symbol(self, name):
        """Private method to find a symbol in the symbol table

        Parameters:
        scope (string): Scope of the symbol
        name (string): Name of the symbol
        
        Returns:
        symbol || None
        """
        for symbol in self.scopes[-1]:
            if symbol.name == name:
                return symbol
        return None
    
    def __get_symbol_stats(self):
        print("Number of integers:", self.integers)
        print("Number of doubles:", self.doubles)
        print("Number of strings:", self.strings)

    def get_symbol_counts(self):
        return self.integers + (2 * self.doubles ) + (4 * self.strings)
    


class Symbol:
    def __init__(self, token, name, value='', symtype=''):
        self.token = token
        self.name = name
        self.type = symtype
        self.memory = ''

        if type(value) == list:
            size = int(value[0])
            empty_list = [None for x in range(size)]
            self.value = empty_list
        else:
            self.value = value
        


    def add_mem(self, memory):
        self.memory = memory
        
    def get_type(self):
        return self.type

    def get_value(self):
        return self.value
    