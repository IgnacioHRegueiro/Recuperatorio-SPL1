/*
 * Projects.h
 *
 *  Created on: 20 jul. 2021
 *      Author: Nacho
 */

#ifndef TEAM_H_
#define TEAM_H_






Team* team_newParametros(char* idTeamStr, char* nameStr, char* membersStr);
Team* team_new();
Team* team_getById(LinkedList* pArrayListTeam, int searchId);

#endif /* TEAM_H_ */
