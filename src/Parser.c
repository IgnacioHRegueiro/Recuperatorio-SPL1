#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Projects.h"
#include "Parser.h"
#include "Controller.h"
#include "Team.h"

int parser_ProjectFromText(char* path , LinkedList* pArrayListProject)
{

	int exito;
	exito = 0;

		if(path!=NULL && pArrayListProject != NULL)
		{

			char idProject[10];
			char idTeam[10];
			char name[64];
			char estimatedWorktime[10];
			char contractor[64];
			char payment[10];


			FILE* File;
			Project* project;
			File = fopen(path,"r");


			while(!feof(File))
			{
				fscanf(File, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n] \n",idProject, idTeam, name, estimatedWorktime, contractor, payment);
				project = project_newParametros(idProject, idTeam, name, estimatedWorktime, contractor, payment);
				ll_add(pArrayListProject, project);
			}

			fclose(File);
			exito = 1;
		}

	return exito;

}


int parser_TeamFromText(char* path , LinkedList* pArrayListTeam)
{
	int exito;
	exito = 0;
		if(path!=NULL && pArrayListTeam != NULL)
		{

			char idTeam[10];
			char name[64];
			char members[10];


			FILE* pFile;
			Team* team;
			pFile = fopen(path,"r");

			 while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^\n]\n",idTeam, name, members);
				 team = team_newParametros(idTeam, name, members);
				ll_add(pArrayListTeam, team);
			}

			fclose(pFile);
			exito = 1;
		}

	return exito;

}

