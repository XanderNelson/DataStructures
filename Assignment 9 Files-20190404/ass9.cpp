#include <vector>
#include <iostream>
#include <queue>
#include "GRAPH_HPP"
using namespace std;

void Graph::addEdge(std::string v1, std::string v2, int distance);
void Graph::addVertex(std::string name);
void Graph::displayEdges();
void Graph::printDFT();
void Graph::printBFT();
void Graph::setAllVerticesUnvisited();
vertex *Graph::findVertex(std::string name);
void Graph::BFT_traversal(vertex *v);
void Graph::DFT_traversal(vertex *v);

Graph::Graph()
{}
Graph::~Graph()
{}

void Graph::addEdge(std::string v1, std::string v2, int distance)
{
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].name == v1)
    {
      for(int j = 0; j < vertices.size(); j++)
      {
        if(vertices[j].name == v2 && i != j)
        {
          Edge ed;
          ed.distance = distance;
          ed.v = &vertices[j];
          vertices[i].Edges.push_back(ed);
        }
      }
    }
  }
}


void Graph::addVertex(std::string name)
{
  bool found = false;

  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].name == name)
    {
      found = true;
    }
  }
  if(!found)
  {
    vertex v;
    v.name = name;
    vertices.push_back(v);
  }
}

void Graph::displayEdges()
{
  for(int i = 0; i < vertices.size(); i++)
  {
      cout<<vertices[i].name<<"-->";

      for(int j = 0; j < vertices[i].Edges.size(); j++)
      {
          cout << vertices[i].Edges[j].v->name << " (" << vertices[i].Edges[j].distance << " miles)";
          if(j < vertices[i].Edges.size() - 1)
          {
            cout << "***";
        }
      }
      cout << endl;
  }
}
void Graph::printBFT()
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        vertex *v = &vertices[i];
        if(!v->visited)
        {
            BFT_traversal(v);
        }
    }
}

void Graph::printDFT()
{
   vertex *d = &vertices[0];
   setAllVerticesUnvisited();
   for(int i = 0; i < vertices.size(); i++)
   {
    vertex *d = &vertices[i];
    if(!d->visited)
    {
     DFT_traversal(d);
     }
   }
}

void Graph::BFT_traversal(vertex* v)
{
  vertex* vStart;

  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].name == v->name)
    {
      vStart = &vertices[i];
    }
}
    vStart->visited = true;

    queue<vertex*> q;

    q.push(vStart);
    vertex* n;
    //cout << q.front()->name << endl;
    while(!q.empty())
    {

      n = q.front();
      cout << q.front()->name << endl;
      q.pop();

      for(int j = 0; j < n->Edges.size(); j++)
      {
        if(!n->Edges[j].v->visited)
        {
          n->Edges[j].v->visited = true;
          q.push(n->Edges[j].v);
          //cout << "hello" << n->Edges[j].v->name << endl;
        }
      }
    }
}

void Graph:: setAllVerticesUnvisited()
{

   std::queue<vertex*> q;

   for(int j = 0; j < vertices.size(); j++)
   {
       vertex* v = &vertices[j];
       q.push(v);
       while(!q.empty())
       {
          v = q.front();
          q.pop();
          v->visited=false;
          for(int i=0; i<(v->Edges).size(); i++)
          {
             if(((v->Edges[i]).v)->visited)
             {
               q.push((v->Edges[i]).v);
             }
          }
       }
   }
}


void Graph::DFT_traversal(vertex *v)
{
   if(!v->visited)
   {
    cout << v->name << endl;
    v->visited = true;
    for(int i = 0; i < v->Edges.size(); i++)
    {
        DFT_traversal((v->Edges[i]).v);
    }
   }
}
