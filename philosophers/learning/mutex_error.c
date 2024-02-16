/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:12:40 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/02/02 09:19:37 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Algunas de las limitaciones que tiene el uso puro de una estrategia de hilos son las siguentes:
- Para devolver datos, la hebra tiene que finalizar.
- No hay forma de compartir datos de forma que los hilos puedan realizar operaciones de lectura o escritura de forma segura.
Para resolver ese problema se provee un mecanismo llamado cerrojo: pthread_mutex que permite realizar las siguientes operaciones:
	- Cerrar un cerrojo con una operación atómica (lock) que permite bloquear el cerrojo. Todos los hilos que intenten 
	bloquear el cerrojo a partir de ese instante fracasarán y se bloquearán.
	- Liberar el cerrojo con otra operación atómica (unlock) que libera el cerrojo y que permite que otro hilo lo use.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_run(void* data)
{
	int i_data;

	sleep(2); 
	printf("[TH_ID:%ld]: Hello from the thread \n", (long)pthread_self());
	printf("[TH_ID:%ld]: Reading %i \n", (long)pthread_self(),(*(int*)data));
	i_data = (*(int*)data);
	sleep(1);
	i_data++;
	(*(int *)data) = i_data;
	printf("[TH_ID:%ld]: Writing %i \n", (long)pthread_self(),(*(int*)data));
	printf("[TH_ID: %ld]: To exit...............\n", (long)pthread_self());
	return (data);
}

int main()
{
	int			i;
	pthread_t	thread[2];
	int			data;
	int			thread_rc;
	int			*ptr_output_data;
	
	data = 0;
	for (i = 0; i < 2; i++)
	{
		printf("[MAIN:%ld]: Starting............ \n", (long)pthread_self());
		thread_rc = pthread_create(&thread[i], NULL, thread_run, &data);
		if (thread_rc != 0)
		{
			printf("Error creating the thread. Code %i", thread_rc);
			return (-1);
		}
	}
	sleep(1);
	printf("[MAIN:%ld]: Thread allocated \n", (long)pthread_self());
	for (i =0;i < 2; i++)
		pthread_join(thread[i],(void **)&ptr_output_data);
	printf("[MAIN:%ld]: Thread returns %d \n", (long)pthread_self(), *ptr_output_data);
	return (0);
} 

/*
Si dos hilos intentan leer y escribir al mismo tiempo pueden darse potencialmente las siguientes 
ejecuciones "erróneas" (todas ellas devuelven 1 en vez de 2).
Este mal comportamiento se llama condición de carrera (race condition en inglés).
Un phtread_muxtex_unlock tiene el siguiente comportamiento sobre el sistema:
Si en el cerrojo mutex hay otros hilos esperando se le cede el paso a uno de ellos 
(que estaba bloqueado en el mismo mutex).
*/
