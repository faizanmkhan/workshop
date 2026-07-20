/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:46:20 by faikhan           #+#    #+#             */
/*   Updated: 2026/06/29 22:50:43 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;

	data.age = 42;
	data.name = "Hello World!";

	std::cout << "Original age: " << data.age << std::endl;
	std::cout << "Original text: " << data.name << std::endl;

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		deserialized = Serializer::deserialize(raw);
    Data aata;
	if (deserialized == &aata)
	{
		std::cout << "Success! \033[36mdeserialized\033[0m is \033[32mequal\033[0m to the original \033[36mraw\033[0m pointer" << std::endl;
		std::cout << "After deserialization age: " << deserialized->age << std::endl;
		std::cout << "After deserialization text: " << deserialized->name << std::endl;
	}
	else
		std::cout << "Failure! \033[36mdeserialized\033[0m is \033[31mnot equal\033[0m to the original \033[36mraw\033[0m pointer" << std::endl;
	
	return (0);
}