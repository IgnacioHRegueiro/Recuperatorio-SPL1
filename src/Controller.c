#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Projects.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Input.h"
#include "Team.h"




int Regueiro_Project_LoadFromText(char* path, LinkedList* pArrayListProject)
{


	int exito;
	exito = 0;

	if(path != NULL && pArrayListProject != NULL)
	{
		if(parser_ProjectFromText(path, pArrayListProject) == 1)
		{

			printf("Se han cargado los datos con éxito \n");
			exito = 1;
		}
		else
		{
			printf("No se han podidos cargar los datos \n");
		}
	}
	else
	{
		printf("No se han podido cargar los datos \n");
	}

	return exito;
}

int Regueiro_Team_LoadFromText(char* path, LinkedList* pArrayListTeam)
{


	int exito;
	exito = 0;



	if(path != NULL && pArrayListTeam!= NULL)
	{

		if(parser_TeamFromText(path, pArrayListTeam) == 1)
		{
			printf("Se han cargado los datos con éxito \n");
			exito = 1;
		}
		else
		{
			printf("No se han podidos cargar los datos \n");
		}
	}
	else
	{
		printf("No se han podido cargar los datos \n");
	}

	return exito;
}





int Regueiro_Project_ListProjects(LinkedList* pArrayListProject, LinkedList* pArrayListTeam)
{
	int exito = 0;
	if(pArrayListProject != NULL)
	{
		int len;
		len = ll_len(pArrayListProject);
		for(int i = 0; i<len; i++)
		{
			project_showProjectByIndex(pArrayListProject, pArrayListTeam, i);
		}
		exito = 1;
	}

    return exito;
}



LinkedList* Regueiro_Project_FilterByContractor(LinkedList* pArrayListProject, LinkedList* pArrayListTeam, int saveLL)
{
	LinkedList* FilteredList = ll_newLinkedList();

	if(pArrayListProject != NULL && pArrayListTeam != NULL)
	{


		printf("Listado de PROYECTOS del Contractor A  \n \n");


		FilteredList = ll_filter(pArrayListProject, project_filterByContractor);

		Regueiro_Project_ListProjects(FilteredList, pArrayListTeam);

		if(saveLL == 0)
		{
			ll_deleteLinkedList(FilteredList);
			FilteredList = NULL;
		}

	}

	return FilteredList;
}

void Regueiro_Project_FilterByWorktime(LinkedList* pArrayListProject, LinkedList* pArrayListTeam)
{
	if(pArrayListProject != NULL && pArrayListTeam != NULL)
	{

		LinkedList* FilteredList = ll_newLinkedList();


		printf("Listado de PROYECTOS con más de 60 horas de trabajo estimado:  \n \n");

		FilteredList = ll_filter(pArrayListProject, project_filterByWorktime);


		Regueiro_Project_ListProjects(FilteredList, pArrayListTeam);


		ll_deleteLinkedList(FilteredList);
	}
}

void Regueiro_Project_CountExcludingContractorB(LinkedList* pArrayListProject, LinkedList* pArrayListTeam)
{
	int contador = 0;
	if(pArrayListProject != NULL && pArrayListTeam != NULL)
	{

		contador = ll_count(pArrayListProject, project_countProjectsExcludingCB);
		if(contador == 0)
		{
			printf("No hay proyectos si se excluye al Contractor B \n");
		}
		else
		{
			printf("La cantidad total de proyectos excluyendo al Contractor B es %d", contador);
		}


	}
}

void Regueiro_Project_CountByPayment(LinkedList* pArrayListProject, LinkedList* pArrayListTeam)
{
	int contador = 0;
	if(pArrayListProject != NULL && pArrayListTeam != NULL)
	{

		contador = ll_count(pArrayListProject, project_countProjectsByPayment);
		if(contador == 0)
		{
			printf("No hay proyectos con una paga mayor a 1800 \n");
		}
		else
		{
			printf("La cantidad total de proyectos con paga mayor a 1800 es de %d", contador);
		}
	}
}

int Regueiro_Project_SaveFilterAsText(char* path , LinkedList* pArrayListProject, LinkedList* pArrayListTeam)
{
	int exito = 0;

	if(path != NULL && pArrayListProject!=NULL)
	{
		FILE* pFile;
		int len;
		Project* aux;
		LinkedList* AuxLL = ll_newLinkedList();


		AuxLL = Regueiro_Project_FilterByContractor(pArrayListProject, pArrayListTeam, 1);
		len = ll_len(AuxLL);

		pFile = fopen(path, "w");

		for(int i = 0; i<len; i++)
		{
			aux = (Project*)ll_get(AuxLL, i);
			fprintf(pFile, "%d,%d,%s,%d,%s,%d \n", aux->idProject, aux->idTeam, aux->name, aux->estimatedWorktime, aux->contractor, aux->payment);
		}

		fclose(pFile);

		exito = 1;
	}
    return exito;
}

