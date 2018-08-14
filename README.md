## FunCore : a User-Friendly Fungi Core Gene Database Website

## Workflow :

~~genomes -> MMseqs2 on Linux -(transform)-> BLASTp output -> Separate Paralog & Ortholog -(now focus on Ortholog)-> delete row which evalue > 1e-5 -> reformat data (table with ID1, ID2, weighted) ->~~ set K(evalue) as a constant to represent the threshold -> **Cluster algo & get representitve protein from each cluster** -> Cytoscape graphs -> decide clusters # -> ... -> store in DB -> GUI webpage

## Cluster :



