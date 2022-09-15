<?php

$ids = $dbh->getCol("SELECT goods_ya2_id as id FROM `goods_ya2` WHERE 1 ORDER BY onstore LIMIT 20  ");
$goods_listing = new Goods_Listing();
$list = $goods_listing->run($ids);
include_once (TPL_PATH."/index.tpl");


unset($list);				