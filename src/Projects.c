/*
 * Projects.c
 *
 *  Created on: 20 jul. 2021
 *      Author: Nacho
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Projects.h"
#include "Input.h"
#include "LinkedList.h"
#include "Team.h"


int Menu()
{
	int option;
	printf("\n  PROYECTOS \n");

	printf("\n 1. Cargar archivo PROYECTOS. \n");
	printf("2. Cargar archivo EQUIPOS.  \n");
	printf("3. Listar PROYECTOS. \n");
	printf("4. Listar PROYECTOS del contractor A.  \n");
	printf("5. Listar PROYECTOS con más de 60 horas de trabajo estimado ... \n");
	printf("6. Listar CANTIDAD de PROYECTOS con más de 1800 de pago.  \n");
	printf("7. Listar CANTIDAD de PROYECTOS excluyendo al Contractor B... \n");
	printf("8. Guardar PROYECTOS del contractor A. \n");
	printf("9. SALIR \n");

	option = GetInt("Ingrese su opción: ");


	return option;
}

Project* project_new()
{
	Project* pProject;
	pProject = (Project*) malloc(sizeof(Project));

	return pProject;

}
Project* project_newParametros(char* idProjectStr, char* idTeamStr, char* nameStr,char* estimatedWorktimeStr, char* contractorStr, char* paymentStr)
{
	Project* pProject;

	pProject = project_new();

	pProject->idProject = atoi(idProjectStr);
	pProject->idTeam = atoi(idTeamStr);
	strcpy(pProject->name, nameStr);
	pProject->estimatedWorktime = atoi(estimatedWorktimeStr);
	strcpy(pProject->contractor, contractorStr);
	pProject->payment = atoi(paymentStr);


	return pProject;
}


void project_showProject(Project* project, Team* team)
{
	printf("Proyecto: %s, Tiempo de trabajo estimado: %d, Contractor: %s, Pago: %d, Equipo: %s, Miembros: %d \n", project->name, project->estimatedWorktime, project->contractor, project->payment, team->name, team->members );
}

void project_showProjectByIndex(LinkedList* pArrayListProject, LinkedList* pArrayListTeam, int index)
{
	Project* auxProject;
	Team* auxTeam;

	auxProject = (Project*) ll_get(pArrayListProject, index);
	auxTeam = team_getById(pArrayListTeam, auxProject->idTeam);
	project_showProject(auxProject, auxTeam);
}

int project_filterByContractor(void* pElement)
{
	int exito = 0;
	Project* aux;

	aux = (void*)pElement;
	if(strcmp(aux->contractor, "Contractor A") == 0)
	{
		exito = 1;
	}
	return exito;
}

int project_filterByWorktime(void* pElement)
{
	int exito = 0;
	Project* aux;

	aux = (Project*)pElement;
	if(aux->estimatedWorktime > 60)
	{
		exito = 1;
	}
	return exito;
}

int project_countProjectsByPayment(void* pElement)
{
	int exito = 0;
	Project* aux;

	aux = (Project*)pElement;
	if(aux->payment > 1800)
	{
		exito = 1;
	}
	return exito;
}

int project_countProjectsExcludingCB(void* pElement)
{
	int exito = 0;
	Project* aux;

	aux = (Project*)pElement;
	if(strcmp(aux->contractor, "Contractor B") != 0)
	{
		exito = 1;
	}
	return exito;
}


