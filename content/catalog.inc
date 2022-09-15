<?php

$cat_id = $state->GetVars('cat_id');

$catalog_row = $catalog->CatalogById($cat_id);


$a = $path->GetPath($cat_parents, 'catalog'); 

$path_a = null;
foreach($a as $r)
    $path_a[]=$r['name'];



$vars['name'] = implode($path_a," &rsaquo; ");


//debug($vars['name']); 



$sql="SELECT goods_ya2_id as id FROM `goods_ya2` WHERE cat=$cat_id ORDER BY sortOrder ";
$ids = $dbh->getCol($sql);

$goods_listing = new Goods_Listing();
$list = $goods_listing->run($ids);
include_once (TPL_PATH."/catalog.tpl");

unset($list);				

