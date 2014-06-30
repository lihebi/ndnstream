#!/bin/sh
# export NS_LOG='*=level_all|prefix_func|prefix_time'
# export NS_LOG='*=level_all|prefix_func|prefix_time|prefix_node'

export NS_LOG='*=level_debug|prefix_func|prefix_time|prefix_node'

./waf --run hebi
