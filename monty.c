# incluye  " monty.h "
global_var var_global;
/ * *
 * principal - función de controlador para el programa monty
 * @ac: int num de argumentos
 * @av: archivo de código de operación
 * Devolución: 0
 * /
int  main ( int ac, char ** av)
{
	stack_t * pila;

	pila = NULL ;
	si (ac! = 2 )
	{
		fprintf (stderr, " USO: archivo monty \ n " );
		salir (EXIT_FAILURE);
	}

	read_file (av [ 1 ], & pila);
    / * recordar liberar memorias * /
	free_dlistint (pila);
	return ( 0 );
}