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
        cout << endl<< endl;
        for (int i =0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    return false;
}

template<class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end)
{
    if( start < MAX && end < MAX)
    {
        Matrix[start][end] = 0;
        Matrix[end][start] = 0;
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

}

template<class LabelType>
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&))
{
    bool found = false;
    int NumVertices = getNumVertices();
    int count = 0;
    int index;
    bool visited[MAX] = {0};
    visited[start] = 1;
    queue<int> erinQueue;
    do
    {
        for(int j = 0; j < MAX; j++)
        {
            if(Matrix[start][j] > 0 && !visited[j])
            {
                erinQueue.push(j);
                count++;
                visted[j] = 1;
                start = j;
                //vist()
            }
            else
            {
                erinQueue.pop();
                start = erinQueue.front();
            }
        }
    } while(count != NumVertices);
}