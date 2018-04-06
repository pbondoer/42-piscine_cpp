/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 07:16:34 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 11:00:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <queue>
#include <stack>

#include "Token.hpp"

std::vector<Token> tokenize(std::string s)
{
	std::vector<Token> q;
	std::stringstream ss(s);

	Token::Type lastType;
	Token t;
	int paren = 0;

	char c;
	while (ss >> c)
	{
		lastType = t.getType();

		if (isdigit(c))
		{
			ss.unget(); // undo the character

			int a;
			ss >> a;

			// number
			t = Token(a);

			if (lastType == Token::PAR_CLOSE)
				throw std::runtime_error ("Can't have non-operand after \
parenthesis");

			if (lastType == Token::NUMBER)
				throw std::runtime_error("Missing operator");

			q.push_back(t);
			continue;
		}

		// character, operation
		t = Token(c);

		if ((lastType == Token::NONE || lastType == Token::PAR_OPEN)
				&& t.getType() != Token::PAR_OPEN)
			throw std::runtime_error("Missing left-hand-side");

		if(lastType == Token::OPERATION &&
				t.getType() == Token::OPERATION)
			throw std::runtime_error("Invalid sequence");



		if (t.getType() == Token::PAR_OPEN)
			paren++;
		else if (t.getType() == Token::PAR_CLOSE)
			paren--;

		if (paren < 0)
			throw std::runtime_error("Unexpected closing parenthesis");

		q.push_back(Token(c));
	}

	if (t.getType() == Token::OPERATION)
		throw std::runtime_error("Missing right-hand-side");

	if (paren > 0)
		throw std::runtime_error("Unclosed parenthesis");

	if (q.size() == 0)
		throw std::runtime_error("No tokens");

	// Display the tokens
	std::cout << "Tokens: ";
	for (std::vector<Token>::iterator it = q.begin();
			it != q.end();
			it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return q;
}

int priority(Token t)
{
	if (t.getType() != Token::OPERATION)
		return 0;

	if (t.getValue() == '+' || t.getValue() == '-')
		return 1;
	else if (t.getValue() == '/' || t.getValue() == '*')
		return 2;
	return 0;
}

std::vector<Token> polish(std::vector<Token> tokens)
{
	std::vector<Token> q;
	std::stack<Token> s;
	Token t;

	for (std::vector<Token>::iterator it = tokens.begin();
			it != tokens.end();
			it++)
	{
		t = *it;

		if (t.getType() == Token::NUMBER)
			q.push_back(t);
		else if (t.getType() == Token::PAR_OPEN)
			s.push(t);
		else if (t.getType() == Token::PAR_CLOSE)
		{
			while (!s.empty() && s.top().getType() != Token::PAR_OPEN)
			{
				q.push_back(s.top());
				s.pop();
			}

			if (s.top().getType() == Token::PAR_OPEN)
				s.pop();
			else
				throw std::runtime_error("Invalid expression");
		}
		else
		{
			while (!s.empty() && priority(t) <= priority(s.top()))
			{
				q.push_back(s.top());
				s.pop();
			}

			s.push(t);
		}
	}

	// output the remaining operations
	while (!s.empty())
	{
		q.push_back(s.top());
		s.pop();
	}

	// Display the postfix tokens
	std::cout << "Postfix: ";
	for (std::vector<Token>::iterator it = q.begin();
			it != q.end();
			it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return q;
}

Token doOperation(Token &left, Token &right, Token &op)
{
	if (op.getValue() == '+')
		return Token(left.getValue() + right.getValue());
	else if (op.getValue() == '-')
		return Token(left.getValue() - right.getValue());
	if (op.getValue() == '*')
		return Token(left.getValue() * right.getValue());
	if (op.getValue() == '/')
	{
		if (right.getValue() == 0)
			throw std::runtime_error("Division by zero");

		return Token(left.getValue() / right.getValue());
	}

	throw std::runtime_error("Unknown operation");
}

void displayStack(std::stack<Token> s)
{
	size_t len = s.size();

	for (size_t i = 0; i < len; i++)
	{
		std::cout << s.top().getValue() << (i < len - 1 ? " " : "");
		s.pop();
	}
}

std::string formatOp(Token &t)
{
	if (t.getType() != Token::OPERATION)
		return "Push";
	if (t.getValue() == '+')
		return "Add";
	else if (t.getValue() == '-')
		return "Substract";
	else if (t.getValue() == '*')
		return "Multiply";
	else if (t.getValue() == '/')
		return "Divide";

	return "Unknown";
}

void display(Token &t, std::stack<Token> s)
{
	std::cout << "I " << std::left << std::setw(15) << t << " | Op "
		<< std::setw(10) << std::left << formatOp(t) << " | ST ";
	displayStack(s);
	std::cout << "]" <<  std::endl;
}

Token solve(std::vector<Token> q)
{
	std::stack<Token> s;

	while (q.size() >= 1)
	{
		Token t = q[0];
		q.erase(q.begin());

		if (t.getType() == Token::OPERATION)
		{
			Token right = s.top();
			s.pop();

			Token left = s.top();
			s.pop();

			s.push(doOperation(left, right, t));
			display(t, s);
		}
		else
		{
			s.push(t);
			display(t, s);
		}
	}

	// result
	std::cout << "Result: " << s.top().getValue() << std::endl;
	return s.top();
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "usage: ./ex04 [expression]" << std::endl;
		return 0;
	}

	try
	{
		solve(polish(tokenize(argv[1])));
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
