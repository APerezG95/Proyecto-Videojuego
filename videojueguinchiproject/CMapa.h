/*    .-----------------------------------------------------------------.    */
/*   /  .-.                                                         .-.  \   */
/*  |  /   \          Proyecto: Videojuego Informática             /   \  |  */
/*  | |\_.  |                                                     |    /| |  */
/*  |\|  | /|         Autor: Mario Pedraza Esteban                |\  | |/|  */
/*  | `---' |                                                     | `---' |  */
/*  |       |         Fecha Última Modificación: 22/04/2016       |       |  */
/*  |       |-----------------------------------------------------|       |  */
/*  \       |                                                     |       /  */
/*   \     /                                                       \     /   */
/*    `---'                                                         `---'    */

#pragma once


class CMapa
{
public:
	enum m_eEnte { PERSONAJE, OBJETO, OBSTACULO, NADA, INACCESIBLE };	//Distintos tipos de cosas que puede contener el mapa
	CMapa(int sizex, int sizey);
	~CMapa();
	m_eEnte ComprobarContenido(int x, int y);
	void ActualizarMapa(int x, int y, m_eEnte estado);
private:
	m_eEnte ** m_eBoard;	//Definimos la matriz que contiene el mapa
	int m_iSizey, m_iSizex;

};