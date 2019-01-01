#pragma once

#include<vector>

class Node
{

public:
	Node();
	Node(class Track* track);
	~Node();

	Node* AppendChild(Node *child);
	void SetParent(Node *parent);
	void PopBackChild();
	void RemoveChild(int position);
	Node* FindChild(int id);

	bool HasChildren() const;
	bool HasParent() const;

	Node* GetParent() const { return mParent; }
	Node* GetChild(int position) const;
	int GetChildrenNumber() const { return mChildren.size(); }
	int GetGrandChildrenNumber();
	class Track* GetTrack() { return mTrack; }

	void Print() const;
	bool SortByNumberOfChildren();
	bool AddVehicleToTrack(class Vehicle* vehicle);

	struct CompareByNumberOfChildren
	{
		bool operator()(const Node* a, const Node* b)
		{
			return (a->GetChildrenNumber() < b->GetChildrenNumber());
		}
	};

private:
	class Track* mTrack;
	Node* mParent;
	std::vector<Node*> mChildren;
	int CountNodesRecursively(Node *root, int& count);
};