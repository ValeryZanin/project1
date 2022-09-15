<?php
$goods_id = $state->getVars('goods_id');
//debug($goods_id);

$row = $dbh->getRow("SELECT * FROM `goods_ya2` WHERE goods_ya2_id = '$goods_id' ");
//debug($row); die;

//characts
$characts = null;
$sql="
SELECT 
    c.name, v.name as value
FROM 
    `goody2chrval` g2v 
    INNER JOIN `characts_value` v ON g2v.value=v.characts_value_id
    INNER JOIN `characts` c ON v.parent=c.characts_id
WHERE
    g2v.goody = '$goods_id'

";
$list =$dbh->getAll($sql);
if(eachable($list)){
    $cnt = count($list);    
    $size = (int)($cnt/2);
    //debug($size);
    $characts = array_chunk($list, $size);
       
}



$row['photo'] = '/img/no-photo550.png';


//$view['path'] = $path->GetPath($cat_parents, 'catalog');






/* js */
//ob_start();
//include_once($TPL_JS_PATH.'/goods_item_js.tpl');
//$view['local_js']['script'] =ob_get_contents();
//ob_end_clean(); 



	

//$goods->UpdateView();

include_once (TPL_PATH."/goods.item.tpl");