/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : Regueiro Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Projects.h"
#include "Controller.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);

	int option;
	int flagProjects = 0;
	int flagTeams = 0;


	LinkedList* ProjectList = ll_newLinkedList();
	LinkedList* TeamList = ll_newLinkedList();


	do
	{
		option = Menu();

		switch(option)
		{
			case 1:
			if(flagProjects == 0)
			{
				 Regueiro_Project_LoadFromText("Proyectos.csv", ProjectList);
				 flagProjects = 1;
			}
			else
			{
				printf("ERROR; Los proyectos ya han sido cargados. \n");
			}
			break;

			case 2:
			if(flagTeams == 0)
			{
				Regueiro_Team_LoadFromText("Equipos.csv", TeamList);
				flagTeams = 1;
			}
			else
			{
				printf("ERROR; los equipos ya han sido cargados.");
			}

			break;

			case 3:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_ListProjects(ProjectList, TeamList);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}
			break;

			case 4:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_FilterByContractor(ProjectList, TeamList, 0);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}
			break;

			case 5:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_FilterByWorktime(ProjectList, TeamList);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}

			break;

			case 6:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_CountByPayment(ProjectList, TeamList);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}
			break;

			case 7:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_CountExcludingContractorB(ProjectList, TeamList);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}
			break;

			case 8:
				if(flagTeams == 1 && flagProjects == 1)
				{
					Regueiro_Project_SaveFilterAsText("ProyectosFiltrados.csv", ProjectList, TeamList);
				}
				else
				{
					printf("ERROR, ambos archivos deben estar cargados antes de realizar esta acción. ");
				}

			break;

			case 9:
			break;

			default:
			printf("Opción inválida. \n");
			break;
		}
	}while(option != 9);
}
