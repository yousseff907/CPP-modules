/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 10:48:49 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
int main(void)
{
	Data originalData(42, "Hello");
	Data *dataPtr = &originalData;

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Data pointer address: " << dataPtr << std::endl;
	std::cout << "Data pointer (as hex): " << std::hex << dataPtr << std::dec << std::endl;
	std::cout << "Data content: id=" << dataPtr->id << ", name=" << dataPtr->name << std::endl;

	uintptr_t serialized = Serializer::serialize(dataPtr);

	std::cout << "\n=== After Serialization ===" << std::endl;
	std::cout << "Serialized value (decimal): " << serialized << std::endl;
	std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;
	std::cout << "Data content: id=" << dataPtr->id << ", name=" << dataPtr->name << std::endl;

	Data *deserializedPtr = Serializer::deserialize(serialized);

	std::cout << "\n=== After Deserialization ===" << std::endl;
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
	std::cout << "Deserialized pointer (as hex): " << std::hex << deserializedPtr << std::dec << std::endl;
	std::cout << "Deserialized content: id=" << deserializedPtr->id << ", name=" << deserializedPtr->name << std::endl;

	return 0;
}
