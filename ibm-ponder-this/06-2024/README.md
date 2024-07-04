# [IBM Ponder This June 2024 Challenge](https://research.ibm.com/haifa/ponderthis/challenges/June2024.html)

Generating all Pythagorean Triples up to a length of 100 digits is not reasonable.

Instead, one can observe that the best way to approximate $\pi$ is with continoud fractions and can apply this approach here to approximate one of the angles inside a Pythagorean triangle from which a Pythagorean triple can be made [1]. More interesting material on the topic can be found [here](https://r-knott.surrey.ac.uk/Pythag/pythag.html#angApproxCalc).
 
The need for high levels of numerical accuracy can be satisfied with the [gmpy](https://gmpy2.readthedocs.io/en/latest/) library.

The solution:
```
A = 7587913369291793355483954865939511319631499416831284048493458379055569840760599914906716656558340169
B = 2415307840951734337432198049563674226343154113717780196065002464546224600850140849822617621311193520
C = 7963048490775380427270778481970239699181818003038762882000266727829823866626269563794546888916000969
```
where A, B and C all have 100 digits is accurate up to 
```
8.231296699055685559347806118953504876248412071290880992269427824106930538656682974986177263921745213479771243157800527424306744943735830262054089084776720650076160160526778081536995735287135272704321354683706076409428779224066505015403265830210986416805633542772937427844386494871967229262170789731707964073712e-100
```


[1] Shiu, P. (1983). The Shapes and Sizes of Pythagorean Triangles. The Mathematical Gazette, 67(439), 33–38. https://doi.org/10.2307/3617358