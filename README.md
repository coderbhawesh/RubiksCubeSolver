It is a Rubik's Cube Solver.
It will have 3 representation of Rubik's Cube (3-d representation, 1-d representation and bitwise representation)
It solve rubiks cube using Korf's Algorithm / IDAStar Algorithm.

The optimal solver is an implementation of [Richard Korf's
algorithm](https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf),
with minor variations, and can solve any cube in 20 moves or fewer.  It works
by searching for solutions using an iterative-deepening depth-first search
combined with A\* (IDA\*).

Iterative-deepening depth-first search (IDDFS) is a tree-traversal algorithm.
Like a breadth-first search (BFS), IDDFS is guaranteed to find an optimal path
from the root node of a tree to a goal node, but it uses much less memory than
a BFS.  Consider a cube as the root of a tree, i.e. depth 0.  Applying each
possible twist of the cube (left, front, right, etc.) brings the cube to a new
node at depth 1, any of which may be the solved state.  If not, applying each
combination of two moves (left-up, left-down, etc.) may solve the cube.  That
continues until a solution is found.

IDDFS alone would take far too much time to solve most scrambled cubes.  There
are 18 possible face twists of the cube, a large branching factor.  After the
first set of twists, some of the moves can be pruned.  For example, turning the
same face twice is redundant: F F is the same as F2; F F' is the same as no
move; F F2 is the same as F'; and so on.  Also, some moves are commutative: F B
is the same as B F; U2 D is the same as D U2; etc.  But even after pruning the
branching factor is over 13, so searching for a solution with raw IDDFS would
take thousands of years on a modern computer!  Here's where A\* comes in.

A\* is a graph-traversal algorithm that's used to find the optimal path from
one node of a graph to another, and, given that a tree is just a graph, it can
be combined with IDDFS.  A\* uses a heuristic to guide the search.  A heuristic
provides an estimated distance (number of moves) from one node (a scrambled
state) to another (the solved state).  For A\* to operate
correctly--specifically, to guarantee an optimal path--the heuristic must never
overestimate the distance.  IDA\* works the same way as IDDFS, but rather than
starting at depth 0 it queries a heuristic for an estimated distance to the
goal state and starts at that depth.  During the search, if the estimated
distance from a node to the goal state exceeds the depth, then the node is
pruned from the tree.  In other words, the heuristic is used to see if moving
from one state of the cube to another brings the cube closer to or farther away
from the solved state.

Richard Korf proposed using a series of pattern databases as a heuristic for
the Rubik's Cube.  One of the databases stores the number of moves required to
solve the corner pieces of any cube.  There are 8 corner cubies, and each can
occupy any of the 8 positions, so there are 8! possible permutations.  Each of
the corner pieces can be oriented in 3 different ways--any of the three
stickers can face up, for example--but the orientations of 7 of the cubies
dictate the orientation of the 8th (by the [laws of the
cube](https://www.ryanheise.com/cube/cube_laws.html)).  Therefore, there are
3^7 possible ways the corners can be orientated.  Altogether then, there are 8!
\* 3^7 possible ways for the corners of the cube to be scrambled, and these
88,179,840 states can be iterated in a reasonable amount of time (30 minutes or
so).  All corner states can be reached in 11 moves or fewer, so each entry in
the corner pattern database can be stored in a nibble (4 bits).  On disk, the
corner pattern database occupies about 42MB.

Korf suggests two additional databases: one for 6 of the 12 edges, and another
for the other 6 edges.  Given that modern developer boxes have plenty of RAM,
this program uses two databases with 7 edges each.  7 edges can occupy 12
positions, so there are 12P7 (12! / (12-7)!) permutations.  Each corner can
be oriented in 2 ways, so there are 2^7 possible orientations of 7 edges.
Again, this is a small enough number of cube states to iterate over, and all
states can be reached in 10 moves or fewer.  Storing each entry in a nibble,
each of the 7-edge databases occupies about 244MB (12P7 \* 2^7 / 2 bytes).

This program uses one additional database that holds the permutations of the 12
edges.  It takes about 228MB (12! / 2 bytes).

Using larger edge databases and the additional edge permutation database
results in a huge speed increase.  Larger databases would result in an even
bigger performance increase, but it's easy to use an enormous amount of memory.
Adding just one more edge piece to the 7-edge database, for example, increases
the size of each database to roughly 2.4GB.

An implementation detail that Korf glazes over in his algorithm is how to
create indexes into these pattern databases.  That is, given a scrambled cube,
how to create a perfect hash of the corner or edge permutations.  To that end,
this program converts permutations to a factorial number system.  There's an
[algorithm](https://en.wikipedia.org/wiki/Factorial_number_system#Permutations)
on Wikipedia that's pretty simple, but it has quadratic complexity.  In
[another](https://www.aaai.org/Papers/AAAI/2005/AAAI05-219.pdf) of Korf's
papers, he describes a linear algorithm, and this program uses the linear
version.  This program was compared against
[another](https://github.com/brownan/Rubiks-Cube-Solver) optimal solver written
in C, and this program is significantly faster.  The main reason for the
improved performance is the linear algorithm that's used to convert
permutations to numbers in a factorial base (a.k.a. generating [Lehmer
codes](https://en.wikipedia.org/wiki/Lehmer_code_)).