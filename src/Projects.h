/*
 * Projects.h
 *
 *  Created on: 20 jul. 2021
 *      Author: Nacho
 */

#ifndef PROJECTS_H_
#define PROJECTS_H_

#include "LinkedList.h"


typedef struct
{
	int idProject;
	int idTeam;
	char name[64];
	int estimatedWorktime;
	char contractor[64];
	int payment;
}Project;

typedef struct
{
	int idTeam;
	char name[64];
	int members;
}Team;

int Menu();
Project* project_new();
Project* project_newParametros(char* idProjectStr, char* idTeamStr, char* nameStr,char* estimatedWorktimeStr, char* contractorStr, char* paymentStr);


void project_showProject(Project* project, Team* team);
void project_showProjectByIndex(LinkedList* pArrayListProject, LinkedList* pArrayListTeam, int index);

int project_filterByWorktime(void* pElement);
int project_filterByContractor(void* pElement);

int project_countProjectsByPayment(void* pElement);
int project_countProjectsExcludingCB(void* pElement);
#endif /* PROJECTS_H_ */
