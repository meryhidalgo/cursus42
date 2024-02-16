/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:44:59 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/02/02 09:16:57 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void	*thread_run(void *data)
{
	//sleep(2); //comentando esta línea podemos cambiar el orden de resultados
	printf("[TH_1:%ld]: Hello from the thread \n", (long)pthread_self());
	(*(int *)data)++;
	sleep(3);
	printf("[TH_1: %ld]: To exit...............\n", (long)pthread_self());
	pthread_exit(data);
}

int	main(void)
{
	pthread_t	thread;
	int			data;
	int			thread_rc;
	int			*ptr_output_data;

	data = 0;
	printf("[MAIN:%ld]: Starting............ \n", (long)pthread_self());
	thread_rc = pthread_create(&thread, NULL, thread_run, &data);
	if (thread_rc != 0)
	{
		printf("Error creating the thread. Code %i", thread_rc);
		return (-1);
	}
	sleep(1);
	printf("[MAIN:%ld]: Thread allocated \n", (long)pthread_self());
	pthread_join(thread, (void **)&ptr_output_data);
	printf("[MAIN:%ld]: Thread returns %d \n", (long)pthread_self(), *ptr_output_data);
	return (0);
} 


/*
La creación de un hilo se hace mediante pthread_create. A partir de este punto, 
si la función no produce error, hay dos hilos de ejecución: el del programa invocante 
y otro cuyo nombre de función se pasa por parámetro y en nuestro caso se corresponde 
con thread_run. Dicha función recibe un puntero a datos y devuelve otro. Típicamente, 
el hilo invocante usa el último parametro de hilo para enviar datos de entrada al nuevo hilo.

El resultado del hilo se devuelve cuando la función con la que se crea el hilo finaliza. 
El hilo devuelve un puntero cuyos resultados se pueden recoger, más tarde, con pthread_join 
desde el hilo padre que lo ha creado.

La configuración de si hilo padre esperará o no por un resultado de su hilo cuando haga 
pthread_join. Esto se controla mediante pthread_attr_setdetachstate.

CREACIÓN HILOS: https://www.it.uc3m.es/pbasanta/asng/course_notes/c_threads_allocation_es.html

*/
