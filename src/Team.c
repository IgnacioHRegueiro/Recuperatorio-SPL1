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


Team* team_new()
{
	Team* pTeam;
	pTeam = (Team*) malloc(sizeof(Team));

	return pTeam;

}
Team* team_newParametros(char* idTeamStr, char* nameStr, char* membersStr)
{
	Team* pTeam;

	pTeam = team_new();

	pTeam->idTeam = atoi(idTeamStr);
	strcpy(pTeam->name, nameStr);
	pTeam->members = atoi(membersStr);


	return pTeam;
}

Team* team_getById(LinkedList* pArrayListTeam, int searchId)
{
	Team* teamBuscado = NULL;
	if(pArrayListTeam!=NULL)
	{
		int len = ll_len(pArrayListTeam);
		Team* aux;
		for(int i = 0; i<len; i++)
		{
			aux = ll_get(pArrayListTeam, i);
			// PUEDE IR UN GETTER
			if(aux->idTeam == searchId)
			{
				teamBuscado = aux;

			}
		}
	}
	return teamBuscado;
}

