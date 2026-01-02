#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include "D:/Programming/Programming Advices/Course 10/Project3_MS/clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	struct stTicket
	{
		string TicketNumber;
		string DateTime;
	};

	queue <stTicket> MyQueueLine;

	string _Prefix;
	int _AverageServeTime;
	int _TotalTickets = 0;
	int _ServedClients = 0;
	int _WaitingClients = 0;

	void _PrintTicket(stTicket Ticket,int WaitingClients, int ServeTime)
	{
		cout << "\n\t\t\t  _______________________\n";

		cout << "\n\t\t\t\t    " << Ticket.TicketNumber;
		cout << "\n\n\t\t\t    " << Ticket.DateTime;
		cout << "\n\t\t\t    Waiting Clients = " << WaitingClients;
		cout << "\n\t\t\t      Serve Time In";
		cout << "\n\t\t\t       " << ServeTime << "  Minutes.\n";

		cout << "\n\t\t\t  _______________________\n";
	}

public:

	clsQueueLine(string Prefix, int AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		stTicket NewTicket;
		NewTicket.TicketNumber = (_Prefix + to_string(MyQueueLine.size() + 1));
		NewTicket.DateTime = clsDate::GetSystemDateToString();

		MyQueueLine.push(NewTicket);

		_TotalTickets++;
		_WaitingClients++;
	}

	void ServeNextClient()
	{
		if(!MyQueueLine.empty())
		{	
			MyQueueLine.pop();
			_ServedClients++;
			if (_WaitingClients > 0)
				_WaitingClients--;
		}
	}

	void PrintInfo() const
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		
		cout << "\n\t\t\t    Prefix = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << _ServedClients;
		cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
		cout << "\n\t\t\t _________________________\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\n\t\tTickets: ";
		
		queue <stTicket> TempQueueLine = MyQueueLine;

		while(!TempQueueLine.empty())
		{
			cout << " " << TempQueueLine.front().TicketNumber << " <-- ";
			TempQueueLine.pop();
		}
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\n\t\tTickets: ";

		queue <stTicket> TempQueueLine = MyQueueLine;
		int Size = TempQueueLine.size();

		stack <stTicket> TempStack;
		for (short i = 0; i < Size; i++)
		{
			TempStack.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStack.empty())
		{
			cout << " " << TempStack.top().TicketNumber << " --> ";
			TempStack.pop();
		}
	}

	void PrintAllTickets()
	{
		cout << "\n\n\n\t\t\t\t--Tickets---\n";

		queue <stTicket> TempQueueLine = MyQueueLine;

		int Index = 0;

		while (!TempQueueLine.empty())
		{
			stTicket Ticket = TempQueueLine.front();

			int WaitingClient = Index;
			int ServeTime = Index * _AverageServeTime;

			_PrintTicket(Ticket, WaitingClient, ServeTime);
			TempQueueLine.pop();

			Index++;
		}
	}
};

