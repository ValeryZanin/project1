<?php

$base_config_row = $state->GetVars('base_config_row'); 

$vars['content'] = $base_config_row['test'];
$vars['name'] = $base_config_row['name'];

if(!$vars['content'])
    $vars['content'] = "<p>under construction</p>";

$path->GetPath($pg_parents, 'content');
$vars['path'] = $path->path;


include_once (TPL_PATH."/content.tpl");				