/*
 * Controller.h
 *
 *  Created on: 20 jul. 2021
 *      Author: Nacho
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int Regueiro_Project_LoadFromText(char* path, LinkedList* pArrayListProject);

int Regueiro_Team_LoadFromText(char* path, LinkedList* pArrayListTeam);

int Regueiro_Project_ListProjects(LinkedList* pArrayListProject, LinkedList* pArrayListTeam);

int Regueiro_Project_SaveFilterAsText(char* path , LinkedList* pArrayListProject, LinkedList* pArrayListTeam);

LinkedList* Regueiro_Project_FilterByContractor(LinkedList* pArrayListProject, LinkedList* pArrayListTeam, int saveLL);

void Regueiro_Project_FilterByWorktime(LinkedList* pArrayListProject, LinkedList* pArrayListTeam);

void Regueiro_Project_CountExcludingContractorB(LinkedList* pArrayListProject, LinkedList* pArrayListTeam);

void Regueiro_Project_CountByPayment(LinkedList* pArrayListProject, LinkedList* pArrayListTeam);


#endif /* CONTROLLER_H_ */
