/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;

} Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee*);
Employee* employee_new();
void employee_printLots(ArrayList*,int, int);
void employee_printAll(ArrayList*);
void employee_delete(ArrayList*);
void employee_add(ArrayList*);
int employee_setId(Employee*, int);
int employee_getId(Employee*);
int employee_setEstado(Employee*, int);
int employee_getEstado(Employee*);
int employee_setNombre(Employee*, char*);
char* employee_getNombre(Employee*);
int employee_setApellido(Employee*, char*);
char* employee_getApellido(Employee*);
int esta(ArrayList*, int);

#endif // _EMPLOYEE_H



