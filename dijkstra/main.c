#include <stdio.h>
#include <stdlib.h>

#define asd 10

#define MAX_EDGE_DISTANCE 999999
#define MAX_VALUE 10000
#define MAX_EDGES 1000
#define MAX_VERTICES 1000
#define VERTEX_DISTANCE_MAP_DISTANCE 0
#define VERTEX_DISTANCE_MAP_EDGE_INDEX 1
#define VERTEX_DISTANCE_MAP_FROM_VALUE 2

#define V 9

// BEGIN - Stack
typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct StackNode
{
    int value;
    StackNode *next;
};

struct Stack
{
    StackNode *first;
    StackNode *last;
    int size;
    int max_capacity;
    void (*push)(Stack *self, int item);
};

Stack *initialize_stack(int max_capacity);
void release_stack(Stack *stack);

void push(Stack *self, int item);

void traverse_post_order_and_release_nodes(StackNode *node);

Stack *initialize_stack(int max_capacity)
{
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->max_capacity = max_capacity;
    stack->first = NULL;
    stack->last = NULL;

    stack->push = &push;

    return stack;
}

void release_stack(Stack *stack)
{
    traverse_post_order_and_release_nodes(stack->first);
    free(stack);
}

void traverse_post_order_and_release_nodes(StackNode *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->next != NULL)
    {
        traverse_post_order_and_release_nodes(node->next);
    }

    free(node);
}

void push(Stack *self, int item)
{
    if (self->size >= self->max_capacity)
    {
        return;
    }

    StackNode *node = malloc(sizeof(StackNode));
    node->next = NULL;
    node->value = item;

    if (self->first == NULL)
    {
        self->first = node;
        self->last = node;
    }
    else
    {
        node->next = self->first;
        self->first = node;
    }

    self->size = self->size + 1;
}
// END - Stack

typedef struct Node Node;
typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Node
{
    Edge *edge;
    Node *next;
    Node *previous;
};

struct Vertex
{
    Edge **edges;
    int edges_size;
    int value;
};

struct Edge
{
    Vertex *from;
    Vertex *to;
    int distance;
    int value;
};

struct Graph
{
    Stack *vertices_available_to_navigate_stack;
    int vertex_index_map[MAX_VALUE];
    int visited_vertex_index_map[MAX_VALUE];
    int vertex_min_distance_map[MAX_VALUE][3];
    int edge_index_map[MAX_VALUE];

    Vertex **vertices;
    int vertices_size;

    Edge **edges;
    int edges_size;
};

Node *initialize_node();
void release_node(Node *node, int only_next);

Vertex *initialize_vertex();
void release_vertex(Vertex *vertex);

Edge *initialize_edge();
void release_edge(Edge *edge);

Graph *initialize_graph();
void release_graph(Graph *graph);

Graph *initialize_graph();
void release_graph(Graph *graph);

void add_vertex_to_graph(Graph *graph, int value);
void add_edge_to_graph(Graph *graph, Vertex *from, Vertex *to, int distance);
void update_relationships(Edge *edge, Vertex *from, Vertex *to);
Edge *add_vertices_and_edge_to_graph(Graph *graph, int from_value, int to_value, int distance);
void reset_graph(Graph *graph, int reset_distance_map);

void reset_vertex_and_edge_index_map(Graph *graph);

Edge *build_edge_from_graph_min_distance_map_propeties(Graph *graph, Vertex *vertex);
void set_graph_min_distance_map_propeties(Graph *graph, Vertex *vertex, int distance, int value, int vertex_edge_index);
Node *add_min_edge_to_shortest_path(Node *shortest_path, Node *latest_node_in_the_path, Edge *min_edge);
Node *build_shortest_path_backwards_to_the_original_vertex_from_min_edge(Graph *graph, Node *shortest_path, Node *latest_node_in_the_path, Edge *min_edge);
Edge *get_min_edge_comparing_all_visited_vertices_in_the_graph(Graph *graph, Vertex *from, int *min_accumulated_distance, int *need_to_reorganize_path, Edge *min_edge);
Edge *get_min_edge_of_adjacent_vertices(Graph *graph, Vertex *from, int *min_accumulated_distance, int *need_to_reorganize_path, int *accumulated_distance);
void *build_shortest_path(Graph *graph, Vertex *from, Vertex *to, Node *shortest_path, Node *latest_node_in_the_path, int first_time);

void print_shortest_path(Node *shortest_path);

int main()
{
    Graph *graph = initialize_graph();

    /*
    reset_vertex_and_edge_index_map(graph);

    Edge *edge_1 = add_vertices_and_edge_to_graph(graph, 1, 2, 3);
    Edge *edge_2 = add_vertices_and_edge_to_graph(graph, 2, 3, 2);
    Edge *edge_3 = add_vertices_and_edge_to_graph(graph, 3, 4, 3);
    Edge *edge_4 = add_vertices_and_edge_to_graph(graph, 4, 5, 4);
    Edge *edge_5 = add_vertices_and_edge_to_graph(graph, 1, 3, 2);
    Edge *edge_6 = add_vertices_and_edge_to_graph(graph, 1, 4, 5);
    Edge *edge_7 = add_vertices_and_edge_to_graph(graph, 2, 4, 1);
    Edge *edge_8 = add_vertices_and_edge_to_graph(graph, 1, 5, 200);
    Edge *edge_9 = add_vertices_and_edge_to_graph(graph, 3, 5, 40);
    Edge *edge_10 = add_vertices_and_edge_to_graph(graph, 2, 5, 8);
    Edge *edge_11 = add_vertices_and_edge_to_graph(graph, 5, 6, 9);
    Edge *edge_12 = add_vertices_and_edge_to_graph(graph, 11, 25, 9);

    add_vertices_and_edge_to_graph(graph, 10, 25, 15);
    add_vertices_and_edge_to_graph(graph, 12, 5, 7);
    add_vertices_and_edge_to_graph(graph, 1, 10, 50);
    add_vertices_and_edge_to_graph(graph, 2, 8, 10);
    add_vertices_and_edge_to_graph(graph, 6, 7, 3);
    add_vertices_and_edge_to_graph(graph, 2, 5, 50);
    add_vertices_and_edge_to_graph(graph, 11, 20, 33);
    add_vertices_and_edge_to_graph(graph, 9, 11, 10);
    add_vertices_and_edge_to_graph(graph, 7, 8, 1);
    add_vertices_and_edge_to_graph(graph, 8, 9, 20);
    add_vertices_and_edge_to_graph(graph, 12, 20, 12);
    add_vertices_and_edge_to_graph(graph, 9, 10, 1);
    add_vertices_and_edge_to_graph(graph, 10, 11, 1);
    reset_graph(graph, 1);

    Node *shortest_path = initialize_node();
    build_shortest_path(graph, edge_1->from, edge_4->to, shortest_path, NULL, 1);
    print_shortest_path(shortest_path);
    release_node(shortest_path, 1);
    reset_graph(graph, 0);

    shortest_path = initialize_node();
    build_shortest_path(graph, edge_1->from, edge_12->to, shortest_path, NULL, 1);
    print_shortest_path(shortest_path);
    release_node(shortest_path, 1);
    reset_graph(graph, 0);

    shortest_path = initialize_node();
    build_shortest_path(graph, edge_1->from, edge_11->to, shortest_path, NULL, 1);
    print_shortest_path(shortest_path);
    release_node(shortest_path, 1);
    reset_graph(graph, 0);
    */

    reset_vertex_and_edge_index_map(graph);

    int graph_space[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    for (int i = 0; i < V; i++)
    {
        for (int k = 0; k < V; k++)
        {
            if (graph_space[i][k] > 0)
            {
                add_vertices_and_edge_to_graph(graph, i, k, graph_space[i][k]);
            }
        }
    }

    reset_graph(graph, 1);

    Node *shortest_path = initialize_node();
    build_shortest_path(graph, graph->vertices[0], graph->vertices[6], shortest_path, NULL, 1);
    print_shortest_path(shortest_path);
    release_node(shortest_path, 1);
    reset_graph(graph, 0);

    release_graph(graph);

    return 0;
}

void print_shortest_path(Node *shortest_path)
{
    int total_distance = 0;
    Node *node = shortest_path;

    do
    {
        printf("\n%d -> %d", node->edge->from->value, node->edge->to->value);
        total_distance = total_distance + node->edge->distance;
        node = node->next;
    } while (node != NULL);

    printf("\ntotal_distance: %d", total_distance);
    printf("\n-----------------------------\n");
}

Node *initialize_node()
{
    Node *node = malloc(sizeof(Node));

    node->edge = NULL;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void release_node(Node *node, int only_next)
{
    if (node == NULL)
    {
        return;
    }

    if (!only_next)
    {
        release_node(node->previous, only_next);
    }
    else
    {
        release_node(node->next, only_next);
    }

    free(node);
}

Vertex *initialize_vertex()
{
    Vertex *vertex = malloc(sizeof(Vertex));

    vertex->edges = malloc(sizeof(Edge) * MAX_EDGES);
    vertex->edges_size = 0;
    vertex->value = 0;

    return vertex;
}

void release_vertex(Vertex *vertex)
{
    if (vertex == NULL)
    {
        return;
    }

    free(vertex->edges);
    free(vertex);
}

Edge *initialize_edge()
{
    Edge *edge = malloc(sizeof(Edge));

    edge->from = NULL;
    edge->to = NULL;
    edge->distance = 0;
    edge->value = 0;

    return edge;
}

void release_edge(Edge *edge)
{
    if (edge == NULL)
    {
        return;
    }

    free(edge);
}

Graph *initialize_graph()
{
    Graph *graph = malloc(sizeof(Graph));

    graph->vertices = malloc(sizeof(Graph) * MAX_VERTICES);
    graph->vertices_size = 0;

    graph->edges = malloc(sizeof(Edge) * MAX_EDGES);
    graph->edges_size = 0;

    return graph;
}

void release_graph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    if (graph->vertices_available_to_navigate_stack->size >= 0)
    {
        release_stack(graph->vertices_available_to_navigate_stack);
    }

    if (graph->edges_size > 0)
    {
        for (int i = 0; i < graph->edges_size; i++)
        {
            Edge *edge = graph->edges[i];

            release_edge(edge);
        }
    }

    if (graph->vertices_size > 0)
    {
        for (int i = 0; i < graph->vertices_size; i++)
        {
            Vertex *vertex = graph->vertices[i];

            release_vertex(vertex);
        }
    }

    free(graph->edges);
    free(graph->vertices);
    free(graph);
}

void add_vertex_to_graph(Graph *graph, int value)
{
    Vertex *vertex = initialize_vertex();

    vertex->value = value;

    graph->vertices[graph->vertices_size] = vertex;
    graph->vertices_size = graph->vertices_size + 1;
}

void add_edge_to_graph(Graph *graph, Vertex *from, Vertex *to, int distance)
{
    Edge *edge = initialize_edge();

    edge->from = from;
    edge->to = to;
    edge->distance = distance;
    edge->value = graph->edges_size + 1;

    graph->edges[graph->edges_size] = edge;
    graph->edges_size = graph->edges_size + 1;
}

void update_relationships(Edge *edge, Vertex *from, Vertex *to)
{
    edge->from = from;
    edge->to = to;

    from->edges[from->edges_size] = edge;
    from->edges_size = from->edges_size + 1;
}

Edge *add_vertices_and_edge_to_graph(Graph *graph, int from_value, int to_value, int distance)
{
    Vertex *from = NULL;
    Vertex *to = NULL;

    if (graph->vertices_size > 0)
    {
        if (graph->vertex_index_map[from_value] >= 0)
        {
            from = graph->vertices[graph->vertex_index_map[from_value]];
        }

        if (graph->vertex_index_map[to_value] >= 0)
        {
            to = graph->vertices[graph->vertex_index_map[to_value]];
        }
    }

    if (from == NULL)
    {
        add_vertex_to_graph(graph, from_value);
        from = graph->vertices[graph->vertices_size - 1];
        graph->vertex_index_map[from->value] = graph->vertices_size - 1;
    }

    if (to == NULL)
    {
        add_vertex_to_graph(graph, to_value);
        to = graph->vertices[graph->vertices_size - 1];
        graph->vertex_index_map[to->value] = graph->vertices_size - 1;
    }

    add_edge_to_graph(graph, from, to, distance);
    Edge *edge = graph->edges[graph->edges_size - 1];
    graph->edge_index_map[edge->value] = graph->edges_size - 1;

    update_relationships(edge, from, to);

    return edge;
}

void reset_graph(Graph *graph, int reset_distance_map)
{

    if (graph->vertices_size > 0)
    {
        for (int i = 0; i < graph->vertices_size; i++)
        {
            Vertex *vertex = graph->vertices[i];
            graph->visited_vertex_index_map[vertex->value] = 0;
        }
    }

    if (reset_distance_map)
    {
        graph->vertices_available_to_navigate_stack = initialize_stack(MAX_VERTICES);

        for (int i = 0; i < MAX_VALUE; i++)
        {
            graph->vertex_min_distance_map[i][VERTEX_DISTANCE_MAP_DISTANCE] = MAX_EDGE_DISTANCE;
            graph->vertex_min_distance_map[i][VERTEX_DISTANCE_MAP_EDGE_INDEX] = -1;
            graph->vertex_min_distance_map[i][VERTEX_DISTANCE_MAP_FROM_VALUE] = -1;
        }
    }
}

void reset_vertex_and_edge_index_map(Graph *graph)
{
    for (int i = 0; i < MAX_VALUE; i++)
    {
        graph->vertex_index_map[i] = -1;
        graph->edge_index_map[i] = -1;
    }
}

Edge *build_edge_from_graph_min_distance_map_propeties(Graph *graph, Vertex *vertex)
{
    int from_value_with_min_distance = graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_FROM_VALUE];
    int from_index = graph->vertex_index_map[from_value_with_min_distance];
    int edge_with_min_distance_map_index = graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_EDGE_INDEX];

    return graph->vertices[from_index]->edges[edge_with_min_distance_map_index];
}

void set_graph_min_distance_map_propeties(Graph *graph, Vertex *vertex, int distance, int value, int vertex_edge_index)
{
    graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_DISTANCE] = distance;
    graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_FROM_VALUE] = value;
    graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_EDGE_INDEX] = vertex_edge_index;
}

Node *add_min_edge_to_shortest_path(Node *shortest_path, Node *latest_node_in_the_path, Edge *min_edge)
{
    Node *new_node = initialize_node();
    new_node->edge = min_edge;

    if (shortest_path->edge == NULL)
    {
        shortest_path->edge = new_node->edge;
        latest_node_in_the_path = shortest_path;

        return latest_node_in_the_path;
    }

    new_node->previous = latest_node_in_the_path;
    latest_node_in_the_path->next = new_node;

    return new_node;
}

Node *build_shortest_path_backwards_to_the_original_vertex_from_min_edge(Graph *graph, Node *shortest_path, Node *latest_node_in_the_path, Edge *min_edge)
{
    Node *new_node = initialize_node();
    new_node->edge = min_edge;

    if (shortest_path->edge != NULL && shortest_path->edge->from->value != min_edge->from->value)
    {
        do
        {
            Edge *edge = build_edge_from_graph_min_distance_map_propeties(graph, new_node->edge->from);
            Node *prev_node = initialize_node();
            prev_node->edge = edge;

            if (new_node->edge->value != min_edge->value)
            {
                new_node->previous = prev_node;
                prev_node->next = new_node;
            }

            new_node = prev_node;
        } while (new_node->edge->from->value != shortest_path->edge->from->value);

        release_node(shortest_path->next, 1);

        shortest_path->edge = new_node->edge;
        shortest_path->next = new_node->next;
        shortest_path->previous = NULL;

        latest_node_in_the_path = shortest_path;

        while (latest_node_in_the_path->next != NULL)
        {
            latest_node_in_the_path = latest_node_in_the_path->next;
        }
    }
    else
    {
        release_node(shortest_path->next, 1);

        latest_node_in_the_path = NULL;
        shortest_path->edge = NULL;
        shortest_path->next = NULL;
        shortest_path->previous = NULL;
    }

    return latest_node_in_the_path;
}

Edge *get_min_edge_comparing_all_visited_vertices_in_the_graph(Graph *graph, Vertex *from, int *min_accumulated_distance, int *need_to_reorganize_path, Edge *min_edge)
{
    Edge *new_min_edge = min_edge;
    graph->visited_vertex_index_map[from->value] = 1;

    if (graph->vertices_available_to_navigate_stack->size > 0)
    {
        StackNode *prev_stack_node = NULL;
        StackNode *stack_node = graph->vertices_available_to_navigate_stack->first;

        while (stack_node != NULL)
        {
            int vertex_index = graph->vertex_index_map[stack_node->value];
            Vertex *vertex = graph->vertices[vertex_index];

            if (graph->visited_vertex_index_map[vertex->value])
            {
                if (prev_stack_node == NULL)
                {
                    graph->vertices_available_to_navigate_stack->first = stack_node->next;
                }
                else
                {
                    prev_stack_node->next = stack_node->next;
                }

                StackNode *stack_node_to_delete = stack_node;
                stack_node = stack_node->next;

                free(stack_node_to_delete);

                graph->vertices_available_to_navigate_stack->size = graph->vertices_available_to_navigate_stack->size - 1;
                continue;
            }

            if (graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_DISTANCE] < *min_accumulated_distance)
            {
                *need_to_reorganize_path = 1;
                new_min_edge = build_edge_from_graph_min_distance_map_propeties(graph, vertex);
                *min_accumulated_distance = graph->vertex_min_distance_map[vertex->value][VERTEX_DISTANCE_MAP_DISTANCE];
            }

            prev_stack_node = stack_node;
            stack_node = stack_node->next;
        }
    }

    graph->visited_vertex_index_map[from->value] = 0;

    return new_min_edge;
}

Edge *get_min_edge_of_adjacent_vertices(Graph *graph, Vertex *from, int *min_accumulated_distance, int *need_to_reorganize_path, int *accumulated_distance)
{
    Edge *min_edge = NULL;

    for (int i = 0; i < from->edges_size; i++)
    {
        Edge *current_edge = from->edges[i];
        Vertex *next_vertex = current_edge->to;

        if (graph->visited_vertex_index_map[next_vertex->value])
        {
            continue;
        }

        int current_acccumulated_distance = *accumulated_distance + current_edge->distance;

        if (current_acccumulated_distance < graph->vertex_min_distance_map[next_vertex->value][VERTEX_DISTANCE_MAP_DISTANCE])
        {
            set_graph_min_distance_map_propeties(graph, next_vertex, current_acccumulated_distance, from->value, i);
            graph->vertices_available_to_navigate_stack->push(graph->vertices_available_to_navigate_stack, next_vertex->value);
        }
        else if (current_acccumulated_distance > graph->vertex_min_distance_map[next_vertex->value][VERTEX_DISTANCE_MAP_DISTANCE])
        {
            *need_to_reorganize_path = 1;
            current_edge = build_edge_from_graph_min_distance_map_propeties(graph, next_vertex);
            current_acccumulated_distance = graph->vertex_min_distance_map[next_vertex->value][VERTEX_DISTANCE_MAP_DISTANCE];
        }

        if ((min_edge == NULL || current_acccumulated_distance < *min_accumulated_distance))
        {
            min_edge = current_edge;
            *min_accumulated_distance = current_acccumulated_distance;
        }
    }

    return min_edge;
}

void *build_shortest_path(Graph *graph, Vertex *from, Vertex *to, Node *shortest_path, Node *latest_node_in_the_path, int first_time)
{
    int need_to_reorganize_path = 0;
    int min_accumulated_distance = MAX_EDGE_DISTANCE;
    int accumulated_distance = latest_node_in_the_path == NULL ? 0 : graph->vertex_min_distance_map[latest_node_in_the_path->edge->to->value][VERTEX_DISTANCE_MAP_DISTANCE];
    Edge *min_edge = get_min_edge_of_adjacent_vertices(graph, from, &min_accumulated_distance, &need_to_reorganize_path, &accumulated_distance);
    min_edge = get_min_edge_comparing_all_visited_vertices_in_the_graph(graph, from, &min_accumulated_distance, &need_to_reorganize_path, min_edge);

    if (need_to_reorganize_path)
    {
        if (shortest_path->edge != NULL && shortest_path->edge->from->value == min_edge->from->value && shortest_path->next == NULL)
        {
            shortest_path->edge = NULL;
        }
        else
        {
            latest_node_in_the_path = build_shortest_path_backwards_to_the_original_vertex_from_min_edge(graph, shortest_path, latest_node_in_the_path, min_edge);
        }
    }

    if (first_time)
    {
        set_graph_min_distance_map_propeties(graph, from, 0, from->value, graph->vertex_min_distance_map[min_edge->to->value][VERTEX_DISTANCE_MAP_EDGE_INDEX]);
    }

    if (min_edge != NULL)
    {
        latest_node_in_the_path = add_min_edge_to_shortest_path(shortest_path, latest_node_in_the_path, min_edge);

        graph->visited_vertex_index_map[from->value] = 1;

        if (min_edge->to->value != to->value)
        {
            build_shortest_path(graph, min_edge->to, to, shortest_path, latest_node_in_the_path, 0);
        }
    }
}
