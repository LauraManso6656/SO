#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	
	MYSQL *conn;
	int err;
	
	//Estructura especial para amacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int cont;
	char jugador [10];
	char consulta [80];
	
	//creamos una conexion al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf("error al crear la conexion: %u %s\n",
			    
			   mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//inicializar la conexion
	conn=mysql_real_connect (conn, "localhost", "root", "mysql", "juego", 0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s \n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
		
	}
	//Consulta SQL para obtener una tabla con todos los datos de la base de datos
	
	err= mysql_query(conn, "SELECT * FROM jugadores");
	if (err!=0){
		printf("Error al consultar datos de la base %u %s \n",
			   mysql_errno(conn), mysql_error(conn));
		exit (1);
		
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	 resultado= mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	//Vamos a buscar el numero de partidas que ha ganado X jugador
	
	printf("Dime el jugador con menos puntos \n");
	scanf("%s", jugador);
	
	//construimos la consulta SQL
	strcpy(consulta, "SELECT jugadores.username FROM jugadores, Participaciones, partidas WHERE Participaciones.puntos=(SELECT MIN(Participaciones.puntos) FROM Participaciones) AND jugadores.id=Participaciones.idJ");	   
		   //hacer consulta
		   err=mysql_query (conn, consulta); 
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
						 mysql_errno(conn), mysql_error(conn));
	exit (1);
	}
	//recogemos el resultado de la consulta 
	resultado = mysql_store_result (conn); 
	row = mysql_fetch_row (resultado);
	if (row == NULL){
		printf ("No se han obtenido datos en la consulta\n");
	}
	else{
		// El resultado debe ser una matriz con una sola fila
		// y una columna que contiene el nombre
		printf("El jugador con menos puntos es: %d\n", row [0]);
	}
	// cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);

	
}

