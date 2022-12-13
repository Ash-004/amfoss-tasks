fn main() {
    let response = reqwest::blocking::get( "https://crypto.com/price",).unwrap().text().unwrap();

    let mut wtr=csv::Writer::from_path("data.csv").unwrap();
    wtr.write_record(&["Crypto Name","Coin","Price","24H Change","24H Volume","Market Cap"]).unwrap();

    
    let document=scraper::Html::parse_document(&response);
    
    let row_selector=scraper::Selector::parse("tr.css-1cxc880").unwrap();
    
    let crypto_selector = scraper::Selector::parse("p.chakra-text.css-rkws3").unwrap();
    let name_selector=scraper::Selector::parse("span.chakra-text.css-1jj7b1a").unwrap();
    let price_selector=scraper::Selector::parse("div.css-b1ilzc").unwrap();
    let c24hc_selector=scraper::Selector::parse("td.css-1b7j986 p").unwrap();    
    let c24hv_selector=scraper::Selector::parse("td.css-1nh9lk8").unwrap();
    let marketcap_selector=scraper::Selector::parse("td.css-1nh9lk8+td").unwrap();

    for element in document.select(&row_selector){
        let crypto_element=element.select(&crypto_selector).next().expect("crypto name");
        let crypto=crypto_element.text().collect::<String>();

        let name_element=element.select(&name_selector).next().expect("crypto name");
        let name=name_element.text().collect::<String>();

        let price_element = element.select(&price_selector).next().expect("crypto price");
        let price = price_element.text().collect::<String>();
  
        let c24hc_element = element.select(&c24hc_selector).next().expect("24hchange");
        let c24hc = c24hc_element.text().collect::<String>();

        let c24hv_element = element.select(&c24hv_selector).next().expect("24hvolume");
        let c24hv = c24hv_element.text().collect::<String>();


        let marketcap_element = element.select(&marketcap_selector).next().unwrap();
        let marketcap = marketcap_element.text().collect::<String>();

        wtr.write_record([&crypto,&name,&price,&c24hc,&c24hv,&marketcap]).expect("wtr.write");
    wtr.flush().expect("wtr.flush");
    } 
    println!("Finished")

}


