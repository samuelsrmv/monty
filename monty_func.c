# incluye  " monty.h "
/ * *
 * read_file: lee un archivo de código de bytes y ejecuta comandos
 * @filename: nombre de ruta al archivo
 * @stack: puntero a la parte superior de la pila
 * /
void  read_file ( char * nombre de archivo, pila_t ** pila)
{
	char * línea;
	size_t i = 0 ;
	int line_count = 1 ;
	instruct_func s;
	int check;
	int  read ;


	var_global. file = fopen (nombre de archivo, " r " );

	if (var_global. file == NULL )
	{
		fprintf (stderr, " Error: No se puede abrir el archivo % s \ n " , nombre de archivo);
		salir (EXIT_FAILURE);
	}

	while (( read = getline (& var_global. buffer , & i, var_global. file ))! = - 1 )
	{
		línea = parse_line (var_global. buffer , stack, line_count);
		if (línea == NULL || línea [ 0 ] == ' # ' )
		{
			line_count ++;
			continuar ;
		}
		s = get_op_func (línea);
		si (s == NULL )
		{
			fprintf (stderr, " L % d : instrucción desconocida % s \ n " , line_count, line);
			salir (EXIT_FAILURE);
		}
		s (pila, line_count);
		line_count ++;
	}
	libre (var_global. buffer );
	check = fclose ( archivo var_global. );
	si (comprobar == - 1 )
		salir (- 1 );
}

/ * *
 * get_op_func: comprueba el código de operación y devuelve la función correcta
 * @str: el código de operación
 * Retorno: devuelve una función, o NULL en caso de falla
 * /
instruct_func get_op_func ( char * str)
{
	int i;

	instrucción_t instruir [] = {
		{ " empujar " , _push},
		{ " pall " , _pall},
		{ " pinta " , _pint},
		{ " pop " , _pop},
		{ " cambiar " , _swap},
		{ " agregar " , _add},
		{ " nop " , _nop},
		{ " sub " , _sub},
		{ " mul " , _mul},
		{ " div " , _div},
		{ " mod " , _mod},
		{ " pchar " , _pchar},
		{ " pstr " , _pstr},
		{ " rotl " , _rotl},
		{ " rotr " , _rotr},
		{ NULL , NULL },
	};

	i = 0 ;
	while (instruir [i]. f ! = NULL && strcmp (instruir [i]. opcode , str)! = 0 )
	{
		i ++;
	}

	volver (instruir [i]. f );
}

/ * *
 * isnumber: comprueba si una cadena es un número
 * @str: cadena que se pasa
 * Retorno: devuelve 1 si la cadena es un número, 0 en caso contrario
 * /
int  isnumber ( char * str)
{
	unsigned  int i;

	si (str == NULL )
		return ( 0 );
	i = 0 ;
	mientras (str [i])
	{
		si (str [ 0 ] == ' - ' )
		{
			i ++;
			continuar ;
		}
		si (! isdigit (str [i]))
			return ( 0 );
		i ++;
	}
	volver ( 1 );
}

/ * *
 * parse_line - analiza una línea para un código de operación y argumentos
 * @line: la línea que se va a analizar
 * @stack: puntero al encabezado de la pila
 * @line_number: el número de línea actual
 * Devolver: devuelve el código de operación o nulo en caso de falla
 * /
char * parse_line ( char * línea, stack_t ** stack, unsigned  int line_number)
{
	char * código_op, * empujar, * arg;
	( vacío ) apilar;

	empujar = " empujar " ;
	op_code = strtok (línea, " \ n  " );
	si (op_code == NULL )
		return ( NULO );

	si ( strcmp (op_code, push) == 0 )
	{
		arg = strtok ( NULO , " \ n  " );
		if (es número (arg) == 1 && arg! = NULL )
		{
			var_global. push_arg = atoi (arg);
		}
		más
		{
			fprintf (stderr, " L % d : uso: push integer \ n " , line_number);
			salir (EXIT_FAILURE);
		}
	}
	return (op_code);
}
