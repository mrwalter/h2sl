#!/bin/bash          

echo ADCG Test 

# ADCG demo 

../build/bin/h2sl-adcg-demo --grammar ../data/grammar/grammar.xml --command "the group of chairs to the side of the robot" --symbol_dictionary ../data/training/navigation_corpus/groups/symbol_dictionary_groundings.xml --world ../data/training/navigation_corpus/groups/example_0036.xml --llm ../data/training/navigation_corpus/groups/llm_adcg.xml --output /tmp/example_adcg.xml --debug 1

# ADCG Tests
# Grammar file provided.
../build/bin/h2sl-adcg-test ../data/training/navigation_corpus/groups/example_0036.xml --llm ../data/training/navigation_corpus/groups/llm_adcg.xml --symbol_dictionary_groundings ../data/training/navigation_corpus/groups/symbol_dictionary_groundings.xml --grammar ../data/grammar/grammar.xml

# Grammar file not provided.
#../build/bin/h2sl-adcg-test ../data/training/navigation_corpus/groups/example_0036.xml --llm ../data/training/navigation_corpus/groups/llm_adcg.xml --symbol_dictionary_groundings ../data/training/navigation_corpus/groups/symbol_dictionary_groundings.xml


