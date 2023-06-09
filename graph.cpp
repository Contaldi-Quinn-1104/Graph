template<class LabelType>
Graph<LabelType>::Graph()
{
    for (int i =0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            Matrix[i][j] = -1;
        }
    }
}

template<class LabelType>
int Graph<LabelType>::getNumVertices() const
{
    bool empty = true;
    int count = 0;
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if (Matrix[i][j] > 0)
            {
                empty = false;
            }
        }
        if(empty == false)
        {
            count++;
            empty = true;
        }
    }
    return count;
}

template<class LabelType>
int Graph<LabelType>::getNumEdges() const
{
    int count = 0;
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if (Matrix[i][j] > 0)
            {
                count++;
            }
        }
    }
    return (count/2);
}

template<class LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end, int edgeWeight)
{
    if(start < MAX && end < MAX)
    {
        Matrix[start][end] = edgeWeight;
        Matrix[end][start] = edgeWeight;
        return true;
    }
    return false;
}

template<class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end)
{
    if( start < MAX && end < MAX)
    {
        Matrix[start][end] = -1;
        Matrix[end][start] = -1;
        return true;
    }
    else
    {
        return false;
    }
}

template<class LabelType>
int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const
{
    return Matrix[start][end];
}

template<class LabelType>
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&))
{
    bool found = false;
    int NumVertices = getNumVertices();
    int count = 0;
    int index;
    bool visited[MAX] = {0};
    stack<int> zyraStack;
    do
    {
        for(int j = 0; j < MAX; j++)
        {
            if(Matrix[start][j] > 0 && !visited[j])
            {
                found = true;
                zyraStack.push(j);
                count++;
                visited[j] = 1;
                start = j;
                break;
            }
            else
            {
                found = false;
            }
        }
        if(found == false)
        {
            visit(zyraStack.top());
            zyraStack.pop();
            start = zyraStack.top();
        }
    } while(count != NumVertices);
    while(!zyraStack.empty())
    {
        visit(zyraStack.top());
        zyraStack.pop();
    }
}

template<class LabelType>
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&))
{
    bool found = false;
    int NumVertices = getNumVertices();
    int count = 0;
    int index;
    bool visited[MAX] = {0};
    queue<int> zyraQueue;
    do
    {
        for(int j = 0; j < MAX; j++)
        {
            if(Matrix[start][j] > 0 && !visited[j])
            {
                found = true;
                zyraQueue.push(j);
                count++;
                visited[j] = 1;
                start = j;
                break;
            }
            else
            {
                found = false;
            }
        }
        if(found == false)
        {
            visit(zyraQueue.front());
            zyraQueue.pop();
            start = zyraQueue.front();
        }
    } while(count != NumVertices);
    while(!zyraQueue.empty())
    {
        visit(zyraQueue.front());
        zyraQueue.pop();
    }
}