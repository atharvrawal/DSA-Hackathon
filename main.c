#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 100
#define MAX_LINES 10
#define MAX_NAME_LEN 50

typedef struct Route {
    char source[MAX_NAME_LEN];
    char destination[MAX_NAME_LEN];
    int cost;
} Route;

typedef struct Station {
    char name[MAX_NAME_LEN];
    int line_count;
    char lines[MAX_LINES][MAX_NAME_LEN];
    int connections[MAX_STATIONS];
    int costs[MAX_STATIONS];
    int connection_count;
} Station;

typedef struct MetroLine {
    char name[MAX_NAME_LEN];
    int station_count;
    char stations[MAX_STATIONS][MAX_NAME_LEN];
} MetroLine;

// Arrays for storing the metro network data
Station stations[MAX_STATIONS];
int station_count = 0;

Route routes[MAX_STATIONS];
int route_count = 0;

MetroLine lines[MAX_LINES];
int line_count = 0;

// Function to initialize a station
void add_station(const char *name) {
    strcpy(stations[station_count].name, name);
    stations[station_count].line_count = 0;
    stations[station_count].connection_count = 0;
    station_count++;
}

// Function to add a route between two stations
void add_route(const char *source, const char *destination, int cost) {
    strcpy(routes[route_count].source, source);
    strcpy(routes[route_count].destination, destination);
    routes[route_count].cost = cost;
    route_count++;
}

// Function to add a metro line
void add_line(const char *line_name) {
    strcpy(lines[line_count].name, line_name);
    lines[line_count].station_count = 0;
    line_count++;
}

// Main function to set up and handle input
int main() {
    int n, m;
    char source[MAX_NAME_LEN], destination[MAX_NAME_LEN];
    int fare;

    // Input for edges (routes)
    printf("Enter the number of edges (routes): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter source, destination, and fare: ");
        scanf("%s %s %d", source, destination, &fare);
        add_route(source, destination, fare);
    }

    // Input for lines and stations
    printf("Enter the number of lines: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char line_name[MAX_NAME_LEN];
        int k;
        
        printf("Enter line name: ");
        scanf("%s", line_name);
        add_line(line_name);
        
        printf("Enter number of stations in line %s: ", line_name);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            char station_name[MAX_NAME_LEN];
            scanf("%s", station_name);
            add_station(station_name);
            strcpy(lines[i].stations[lines[i].station_count++], station_name);
        }
    }

    // Placeholder for future functionalities
    
    return 0;
}
