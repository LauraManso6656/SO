DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;
USE juego;

CREATE TABLE jugadores(
id INT PRIMARY KEY NOT NULL,
username VARCHAR (20) NOT NULL,
password VARCHAR(20) NOT NULL,

) ENGINE InnoDB;


CREATE TABLE partidas(

id_partidas INT PRIMARY KEY NOT NULL,
fecha_hora_fin DATE,
duracion FLOAT,
ganador VARCHAR(20),
) ENGINE InnoDB;


CREATE TABLE Participaciones (
idJ INT NOT NULL,
idP INT NOT NULL,
puntos INT NOT NULL,

FOREIGN KEY (idJ) REFERENCES jugadores (id),
FOREIGN KEY (idP) REFERENCES partidas (id),
) ENGINE InnoDB;

INSERT INTO jugadores VALUES (1, 'LauraManso', 1234);
INSERT INTO jugadores Values (2, 'Crisbelbo', 6656);
INSERT INTO jugadores VALUES (3, 'Queralt', 1111);
INSERT INTO jugadores VALUES (4, 'user1', 2222);

INSERT INTO partidas VALUES (1, 03/10/2023, 1.3, 'user1');

INSERT INTO Participaciones VALUES (1,1,12); 
