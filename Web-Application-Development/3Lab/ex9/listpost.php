<?php
    $postsInfo = curl_init();
    curl_setopt($postsInfo, CURLOPT_URL, "https://dummyapi.io/data/v1/post/");
    curl_setopt($postsInfo, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($postsInfo, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $postsResponse = curl_exec($postsInfo);
    curl_close($postsInfo);
    $postsData = json_decode($postsResponse, true);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <title>Document</title>
</head>
<body>
    <section class="d-flex align-items-center justify-content-center h-100 w-100">
        <div class="container d-flex align-items-center justify-content-center h-100 w-100">
            <div class="col-12 col-md-9 col-lg-7 col-xl-6">
                <div class="card">
                    <div class="card-body">
                    <?php foreach ($postsData['data'] as $post) { ?>
                        <a href="post.php?postid=<?php echo $post['id'] ?>">
                            <h3><?php echo $post['text']; ?></h3>
                            <img src="<?php echo $post['image'] ?>" alt="post" class="img-fluid mb-3">
                        </a>
                        <p><?php echo $post['publishDate']; ?></p>
                        <hr>
                    <?php } ?>
                    </div>
                </div>
            </div>
        </div>
    </section>
</body>
</html>
