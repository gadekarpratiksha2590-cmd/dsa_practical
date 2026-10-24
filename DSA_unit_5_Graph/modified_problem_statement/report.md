## Problem Statement

Design an interactive campus infrastructure tool in C++ that models building connections as a weighted graph. The program must dynamically compute the Minimum Spanning Tree (MST) using Kruskal's Algorithm, track the accumulation of costs in real-time, handle dynamic cable cost updates, and automatically detect if structural gaps leave parts of the campus disconnected.




## Conclusion

Integrating modularity into this codebase allows it to seamlessly re-evaluate network configurations when structural data changes. The inclusion of trace logs provides complete transparency over cost accumulation. Most importantly, the validation mechanism successfully screens for incomplete networks, ensuring structural gaps are flagged before deployment begins.
