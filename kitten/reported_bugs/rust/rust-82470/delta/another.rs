use async_trait::async_trait;
#[async_trait]
trait My<'tx> {

    async fn get_conn<E>(&'tx mut self) -> api::Result<E>
    where E: Executor<'tx>;

    //#[tracing::instrument]
    pub async fn save_tmp(&self, session_id: &[u8], ip: &str, expiration: i64, field: &str, data: &[u8]) -> api::Result<()> {
        sqlx::query("replace into `tmp` values (?, INET_ATON(?), FROM_UNIXTIME(?), ?, ?)")
            .bind(session_id)
            .bind(ip)
            .bind(expiration)
            .bind(field)
            .bind(data)
            .execute(todo!()).await.map_err(|e| api::Error::ServerSideError(e.into()))?;
        Ok(())
    }



